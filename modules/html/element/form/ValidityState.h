namespace Newtoo
{

    class ValidityState
    {

    public:

        ValidityState();

        bool valueMissing()                           const { return mValueMissing; }
        bool typeMismatch()                           const { return mTypeMismatch; }
        bool patternMismatch()                        const { return mPatternMismatch; }
        bool tooLong()                                const { return mTooLong; }
        bool tooShort()                               const { return mTooShort; }
        bool rangeUnderflow()                         const { return mRangeUnderflow; }
        bool rangeOverflow()                          const { return mRangeOverflow; }
        bool stepMismatch()                           const { return mStepMismatch; }
        bool badInput()                               const { return mBadInput; }
        bool customError()                            const { return mCustomError; }
        bool valid()                                  const { return mValid; }

        void setValueMissing(bool b)                        { mValueMissing = b; }
        void setTypeMismatch(bool b)                        { mValueMissing = b; }
        void setPatternMismatch(bool b)                     { mValueMissing = b; }
        void setTooLong(bool b)                             { mValueMissing = b; }
        void setTooShort(bool b)                            { mValueMissing = b; }
        void setRangeUnderflow(bool b)                      { mValueMissing = b; }
        void setRangeOverflow(bool b)                       { mValueMissing = b; }
        void setStepMismatch(bool b)                        { mValueMissing = b; }
        void setBadInput(bool b)                            { mValueMissing = b; }
        void setCustomError(bool b)                         { mValueMissing = b; }
        void setValid(bool b)                               { mValueMissing = b; }

    private:

        bool mValueMissing;
        bool mTypeMismatch;
        bool mPatternMismatch;
        bool mTooLong;
        bool mTooShort;
        bool mRangeUnderflow;
        bool mRangeOverflow;
        bool mStepMismatch;
        bool mBadInput;
        bool mCustomError;
        bool mValid;
    };

}
