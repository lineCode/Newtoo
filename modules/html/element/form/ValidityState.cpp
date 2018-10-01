#include "ValidityState.h"

namespace Newtoo
{

    ValidityState::ValidityState() : mValueMissing(false), mTypeMismatch(false), mPatternMismatch(false),
        mTooLong(false), mTooShort(false), mRangeUnderflow(false), mRangeOverflow(false),
        mStepMismatch(false), mBadInput(false), mCustomError(false), mValid(false)
    {}

}
