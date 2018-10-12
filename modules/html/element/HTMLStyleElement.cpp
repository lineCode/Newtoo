#include "HTMLStyleElement.h"
#include "../../cssom/style/CSSStyleSheet.h"
#include "../../cssom/rule/CSSRule.h"

namespace Newtoo
{

    HTMLStyleElement::HTMLStyleElement()
    {}

    HTMLStyleElement::HTMLStyleElement(DOMString aNamespace, DOMString qualifiedName, DOMString aPrefix)
        :HTMLElement(aNamespace, qualifiedName, aPrefix)
    {}

    CSSStyleDeclaration HTMLStyleElement::userAgentStyle()
    {
        CSSStyleDeclaration st;
        st.setProperty("display", "none", UAPropertyPriority);
        return st;
    }

    Node* HTMLStyleElement::cloneNode(bool deep)
    {
        return new HTMLStyleElement(*this, deep);
    }

    DOMString HTMLStyleElement::innerHTML()
    {
        return mCssInnerHTML;
    }
    void HTMLStyleElement::setInnerHTML(DOMString aHTML)
    {
        if(sheet() == (StyleSheet*)NoStyleSheet)
            return;

        CSSStyleSheet* s = (CSSStyleSheet*)sheet();

        for(unsigned i = 0; i < s->cssRules().length(); i++)
        {
            s->cssRules().removeRule(0);
        }
        s->cssRules().shrinkToFit();
        s->appendCSS(aHTML);

        mCssInnerHTML = aHTML;
    }

}
