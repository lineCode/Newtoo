#include "StyleAssembler.h"
#include "../assembly/CSSSelectorParser.h"
#include "../cssom/style/CSSStyleSheet.h"
#include "../cssom/rule/CSSStyleRule.h"
#include "../html/element/pseudo/PseudoBeforeElement.h"
#include "../html/element/pseudo/PseudoAfterElement.h"

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
        std::vector<Element*> pseudoElementGC; // удаляет не нужные псевдоэлементы

        for(unsigned s = 0; s < styles.lengthReflect(); s++)
        {
            CSSStyleSheet* stylesheet = (CSSStyleSheet*)styles.itemReflect(s);

            for(unsigned i = 0; i < stylesheet->cssRules().length(); i++)
            {
                CSSRule* rule = stylesheet->cssRules().item(i);
                if(rule->type() == CSSRule::STYLE_RULE)
                {
                    CSSStyleRule* srule = (CSSStyleRule*)rule;
                    switch(CSSSelectorParser::elementMatches(element, srule->selectorText()))
                    {
                        case CSSSelectorParser::Assigned:
                        {
                            CSSStyleDeclaration& st = srule->style();
                            element->mergedStyle().clear();
                            unsigned long rulePriority = srule->priority();
                            for(unsigned p = 0; p < st.length(); p++)
                            {
                                CSSStyleDeclaration::StyleProperty prop = st.propertyItem(p);
                                element->mergedStyle().putProperty(prop.id, prop.value, prop.priority,
                                                                   rulePriority);
                            }
                            if(element->hasPseudoBefore())
                            {
                                Element* pseudo = element->previousElementSibling();
                                if(pseudo != 0)
                                {
                                    if(pseudo->isPseudoBeforeAssigned())
                                    {
                                        element->setHasPseudoBefore(false);
                                        pseudoElementGC.push_back(pseudo);
                                    }
                                }
                            }
                            if(element->hasPseudoAfter())
                            {
                                Element* pseudo = element->nextElementSibling();
                                if(pseudo != 0)
                                {
                                    if(pseudo->isPseudoAfterAssigned())
                                    {
                                        element->setHasPseudoAfter(false);
                                        pseudoElementGC.push_back(pseudo);
                                    }
                                }
                            }
                            break;
                        }
                        case CSSSelectorParser::Before:
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
                                element->setHasPseudoBefore(true);
                                DOMString val = processContentValue(contentprop->value);
                                PseudoBeforeElement* pseudo = new PseudoBeforeElement(val, st);
                                element->parentNode()->insertBefore(pseudo, element);
                            }
                            break;
                        }
                        case CSSSelectorParser::After:
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
                                element->setHasPseudoAfter(true);
                                DOMString val = processContentValue(contentprop->value);
                                PseudoAfterElement* pseudo = new PseudoAfterElement(val, st);
                                element->parentNode()->insertAfter(pseudo, element);
                            }
                            break;
                        }
                        case CSSSelectorParser::NotMatches:
                        {
                            break;
                        }
                    } // switch
                } // if STYLE_RULE
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

}
