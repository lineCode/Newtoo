#include "StyleAssembler.h"
#include "../assembly/CSSSelectorParser.h"
#include "../cssom/style/CSSStyleSheet.h"
#include "../cssom/rule/CSSStyleRule.h"

namespace Newtoo
{

    void StyleAssembler::cascade(Element* element, StyleSheetListReflect& styles)
    {
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
                            break;
                        }
                        case CSSSelectorParser::Before:
                        {
                            /*
                            Element* pseudo = element->pseudoBefore();
                            if(pseudo != 0)
                            {

                            } else
                            {

                            }
                            */
                            break;
                        }
                        case CSSSelectorParser::After:
                        {
                            break;
                        }
                        case CSSSelectorParser::NotMatches:
                        {
                            break;
                        }
                    }
                }
            }
        }

        for(unsigned i = 0; i < element->childNodes().length(); i++)
        {
            if(element->childNodes().item(i)->nodeType() == Node::ELEMENT_NODE)
                cascade((Element*)element->childNodes().item(i), styles);
        }
    }

}
