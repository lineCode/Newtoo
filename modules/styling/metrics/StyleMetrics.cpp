#include "StyleMetrics.h"

#ifdef n2_cssstyledeclaration
#include "../../cssom/style/CSSStyleDeclaration.h"
#endif

namespace Newtoo
{
    StyleMetrics::StyleMetrics(StyleMetrics& ref) : mAssignedParent(ref.mAssignedParent)
    {}

    StyleMetrics::StyleMetrics(StyleMetrics* parent)
    {

    }

    StyleMetrics::StyleMetrics(CSSStyleDeclaration* importFrom, StyleMetrics* parent)
    {
#ifdef n2_cssstyledeclaration
        // TODO
#endif
    }

    StyleMetrics::StyleMetrics()
    {
    }

    unsigned long StyleMetrics::length()
    {
        return 0;
    }

    DOMString StyleMetrics::item(unsigned long index)
    {
        return DOMString("");
    }

    DOMString StyleMetrics::getPropertyValue(DOMString propertyID)
    {
        return DOMString("");
    }

    void StyleMetrics::setPropertyValue(DOMString propertyID, DOMString value)
    {

    }

    CSSOMString StyleMetrics::keywordToString(short value)
    {
        // TODO
    }

    short StyleMetrics::keywordFromString(CSSOMString str)
    {
        // TODO
    }

    bool StyleMetrics::isKeyword(CSSOMString str)
    {
        // TODO
    }

    StyleMetrics* StyleMetrics::assignedParent() const
    {
        return mAssignedParent;
    }

    void StyleMetrics::setAssignedParent(StyleMetrics* aAssignedParent)
    {
        mAssignedParent = aAssignedParent;
    }

    double StyleMetrics::valueOfPropertyWithNumericValue(DOMString propertyID)
    {
        return 0.0;
    }


} // namespace Newtoo
