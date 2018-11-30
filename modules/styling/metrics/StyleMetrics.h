#pragma once

#include "../StylingEngine_dependencies.h"

namespace Newtoo
{
    class CSSStyleDeclaration;

    class StyleMetrics
    {
    public:
        StyleMetrics(StyleMetrics* parent);
        StyleMetrics(CSSStyleDeclaration* importFrom, StyleMetrics* parent = 0);
        StyleMetrics(StyleMetrics& ref);
        StyleMetrics();

        const short Inherit = 0x7FFD;
        const short Initial = 0x7FFE;
        const short Unset = 0x7FFF;

        virtual unsigned long length();

        virtual DOMString item(unsigned long index);

        virtual DOMString getPropertyValue(DOMString propertyID);

        virtual void setPropertyValue(DOMString propertyID, DOMString value);

        const short NoKeyword = 0x7FFA;

        static CSSOMString keywordToString(short value);

        static short keywordFromString(CSSOMString str);

        static bool isKeyword(CSSOMString str);

        StyleMetrics* assignedParent() const;
        void setAssignedParent(StyleMetrics* aAssignedParent);

        virtual double valueOfPropertyWithNumericValue(DOMString propertyID);



        protected:
            StyleMetrics* mAssignedParent;

    };


} // namespace Newtoo
