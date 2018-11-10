#pragma once

namespace Newtoo
{
    class SVGAnimatedBoolean
    {
    public:
        SVGAnimatedBoolean(SVGAnimatedBoolean& ref);
        SVGAnimatedBoolean();

        bool baseVal() const;
        void setBaseVal(bool aBaseVal);

        bool animVal() const;



    protected:
        bool mBaseVal;
        bool mAnimVal;

    };


} // namespace Newtoo
