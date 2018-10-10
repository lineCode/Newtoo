#include "StyleAssembler.h"
#include "../assembly/selector/express/SelectorParserExpress.h"
#include "../cssom/style/CSSStyleSheet.h"
#include "../cssom/rule/CSSStyleRule.h"
#include "../html/element/pseudo/PseudoBeforeElement.h"
#include "../html/element/pseudo/PseudoAfterElement.h"
#include "../dom/node/Document.h"

#include <omp.h>

namespace Newtoo
{

#define WHITESPACE_CHAR ' '
#define QUOTE_CHAR_ALTERNATIVE '\''
#define QUOTE_CHAR '"'

    const char contentStylePropertyId[] = "content";

    DOMString processContentValue(DOMString val)
    {
        while(val.startsWithChar(WHITESPACE_CHAR))
            val.eraseThis(0, 1);
        while(val.endsWithChar(WHITESPACE_CHAR))
            val = val.substring(0, val.size() - 1);
        if(val.startsWithChar(QUOTE_CHAR) or val.startsWithChar(QUOTE_CHAR_ALTERNATIVE))
            val.eraseThis(0, 1);
        if(val.endsWithChar(QUOTE_CHAR) or val.endsWithChar(QUOTE_CHAR_ALTERNATIVE))
            val = val.substring(0, val.size() - 1);
        return val;
    }

    void StyleAssembler::cascade(Element* element, StyleSheetListReflect& styles)
    {
        element->mergedStyle().clear();

        for(unsigned i = 0; i < element->style().length(); i++)
            element->mergedStyle().addProperty(element->style().propertyItem(i));

        CSSStyleDeclaration uaStyle = element->userAgentStyle();
        for(unsigned u = 0; u < uaStyle.length(); u++)
        {
            CSSStyleDeclaration::StyleProperty uaProp = uaStyle.propertyItem(u);
            element->mergedStyle().putProperty(uaProp.id, uaProp.value,
                                               uaProp.priority);
        }

        std::vector<Element*> pseudoElementGC; // удаляет не нужные псевдоэлементы

        for(unsigned s = 0; s < styles.lengthReflect(); s++)
        {
            CSSStyleSheet* stylesheet = (CSSStyleSheet*)styles.itemReflect(s);

            for(unsigned i = 0; i < stylesheet->cssRules().length(); i++)
            {
                CSSRule* rule = stylesheet->cssRules().item(i);
                if(rule->type() != CSSRule::STYLE_RULE)
                    continue;

                CSSStyleRule* srule = (CSSStyleRule*)rule;

                if(srule->selectorRecency().updated())
                    continue;
                else srule->selectorRecency().affect();

                SelectorData& data = srule->selectorData();

                bool pseudoAfterAffected = false,
                     pseudoBeforeAffected = false,
                     assigned = false;

                for(unsigned g = 0; g < data.groups().size(); g++)
                {
                    SelectorGroup::Result result = data.groups()[g].matches(element);

                    switch(result)
                    {
                        case SelectorGroup::Assigned:
                        {
                            assigned = true;
                            break;
                        }
                        case SelectorGroup::Firstletter:
                        {
                            break;
                        }
                        case SelectorGroup::Firstline:
                        {
                            break;
                        }
                        case SelectorGroup::Selection:
                        {
                            break;
                        }
                        case SelectorGroup::Before:
                        {
                            pseudoBeforeAffected = true;
                            break;
                        }
                        case SelectorGroup::After:
                        {
                            pseudoAfterAffected = true;
                            break;
                        }
                        case SelectorGroup::NotMatches:
                        {
                            break;
                        }
                    } // switch
                }

                if(assigned)
                {
                    CSSStyleDeclaration& st = srule->style();

                    for(unsigned p = 0; p < st.length(); p++)
                    {
                        CSSStyleDeclaration::StyleProperty& prop = st.propertyItem(p);
                        element->mergedStyle().putProperty(prop.id, prop.value, prop.priority);
                    }

                    if(element->hasPseudoBefore())
                        pseudoElementGC.push_back(element->pseudoBefore());

                    if(element->hasPseudoAfter())
                        pseudoElementGC.push_back(element->pseudoAfter());
                }

                if(pseudoBeforeAffected)
                {
                    CSSStyleDeclaration& st = srule->style();
                    CSSStyleDeclaration::StyleProperty* contentprop = 0;
                    for(unsigned i = 0; i < st.length(); i++)
                    {
                        if(st.propertyItem(i).id == contentStylePropertyId)
                        {
                            contentprop = &st.propertyItem(i);
                            break;
                        }
                    }
                    if(contentprop != 0 and element->parentNode() != 0)
                    {
                        DOMString val = processContentValue(contentprop->value);

                        PseudoBeforeElement* pseudo = new PseudoBeforeElement(element, val, st);
                        element->parentNode()->insertBefore(pseudo, element);
                        element->setPseudoBefore(pseudo);
                    }
                }

                if(pseudoAfterAffected)
                {
                    CSSStyleDeclaration& st = srule->style();
                    CSSStyleDeclaration::StyleProperty* contentprop = 0;
                    for(unsigned i = 0; i < st.length(); i++)
                    {
                        if(st.propertyItem(i).id == contentStylePropertyId)
                        {
                            contentprop = &st.propertyItem(i);
                            break;
                        }
                    }
                    if(contentprop != 0 and element->parentNode() != 0)
                    {
                        DOMString val = processContentValue(contentprop->value);

                        PseudoAfterElement* pseudo = new PseudoAfterElement(element, val, st);
                        element->parentNode()->insertAfter(pseudo, element);
                        element->setPseudoAfter(pseudo);
                    }
                }

            }
        }

        for(unsigned i = 0; i < pseudoElementGC.size(); i++)
        {
            pseudoElementGC[i]->remove();
        }

        for(unsigned i = 0; i < element->childNodes().length(); i++)
        {
            if(element->childNodes().item(i)->nodeType() == Node::ELEMENT_NODE)
                cascade((Element*)element->childNodes().item(i), styles);
        }
    }

    void StyleAssembler::cascade(Document* document)
    {
        HTMLElement* target = document->body();
        if(target != 0)
        {
            StyleAssembler::cascade((Element*)target, (StyleSheetListReflect&)document->styleSheets());
        } else
        {
            for(unsigned i = 0; i < document->childNodes().length(); i++)
            {
                if(document->childNodes().item(i)->nodeType() == Node::ELEMENT_NODE)
                {
                    StyleAssembler::cascade((Element*)document->childNodes().item(i),
                                    (StyleSheetListReflect&)document->styleSheets());
                }
            }
        }
    }

}
