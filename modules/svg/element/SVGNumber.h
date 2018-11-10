#pragma once

namespace Newtoo
{

    class SVGNumber
    {
    public:
        SVGNumber(SVGNumber& ref);
        SVGNumber();

        float value() const;
        void setValue(float aValue);



    protected:
        float mValue;

    };

}
