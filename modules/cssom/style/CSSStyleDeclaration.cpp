#include "CSSStyleDeclaration.h"

namespace Newtoo
{

    CSSStyleDeclaration::CSSStyleDeclaration()
        :mParentRule(0)
    {}

    DOMString CSSStyleDeclaration::cssText()
    {
        DOMString text;

        unsigned long len = length();
        for(unsigned i = 0; i < len; i++)
        {
            StyleProperty prop = mStylePropertyList[i];
            text += prop.id;
            text += ": ";
            text += prop.value;
            if(prop.priority == ImportantPriority)
            {
                text += " ";
                text += ImportantPriority;
            }
            text += ";";
            if(i < len - 1)
            {
                text += " ";
            }
        }

        return text;
    }

    namespace _setCssText // работает, но появляются какие-то каракули
    {

        enum Location
        {
            PROPERTY, VALUE, IMPORTANT
        };

        struct State
        {
            CSSStyleDeclaration* declaration;
            unsigned long index, size;
            String defaultPriority;
            String& reference;
            Location location;
            bool inQuotes;
            char quote;

            CSSStyleDeclaration::StyleProperty prop;

            void newprop()
            {
                declaration->addProperty(prop);
                prop = CSSStyleDeclaration::StyleProperty();
                location = PROPERTY;
            }
            void finish()
            {
                declaration->addProperty(prop);
            }

            State(CSSStyleDeclaration* aDec, String aRef, String aDefPriority)
                : declaration(aDec),
                  index(0),
                  size(aRef.size()),
                  defaultPriority(aDefPriority),
                  reference(aRef),
                  location(PROPERTY),
                  inQuotes(false),
                  quote(0)
            {}
        };

        const char quote = '"';
        const char quote_alternative = '\'';
        const char important_prefix = '!';
        const char splitter = ';';
        const char equals = ':';

        bool proceed(State* state)
        {
            if(state->index == state->size)
            {
                state->finish();
                return false;
            }

            char c = state->reference[state->index];

            state->index++;

            if(state->inQuotes)
            {
                if(c == quote && c == quote_alternative) {
                    state->inQuotes = true;
                    return true;
                }
            } else
            {
                if(c == state->quote) {
                    state->inQuotes = false;
                    return true;
                }
            }

            switch(state->location)
            {
                case PROPERTY:
                {
                    if(c == equals)
                    {
                        state->location = VALUE;
                    } else
                    {
                        state->prop.id += c;
                    }
                    break;
                }
                case VALUE:
                {
                    if(c == splitter)
                    {
                        state->newprop();
                    }
                    else if(c == important_prefix)
                    {
                        state->location = IMPORTANT;
                    } else
                    {
                        state->prop.value += c;
                    }
                    break;
                }
                case IMPORTANT:
                {
                    if(c == splitter)
                    {
                        state->newprop();
                    } else
                    {
                        state->prop.priority += c;
                    }
                    break;
                }
            }
            return true;
        }
    }

    void CSSStyleDeclaration::setCssText(DOMString css, DOMString priority)
    {
        _setCssText::State* state = new _setCssText::State(this, css, priority);
        while(proceed(state));
        delete state;
    }

    unsigned long CSSStyleDeclaration::length()
    {
        return mStylePropertyList.size();
    }

    DOMString CSSStyleDeclaration::item(unsigned long index)
    {
        if(index >= length())
            return DOMString("");

        return mStylePropertyList[index].value;
    }

    DOMString CSSStyleDeclaration::getPropertyValue(DOMString property)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(mStylePropertyList[i].id == property)
                return mStylePropertyList[i].value;
        }
        return DOMString("");
    }
    DOMString CSSStyleDeclaration::getPropertyPriority(DOMString property)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(mStylePropertyList[i].id == property)
                return mStylePropertyList[i].priority;
        }
        return DOMString("");
    }

    void CSSStyleDeclaration::setProperty(DOMString property, DOMString value, DOMString priority)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(mStylePropertyList[i].id == property)
            {
                mStylePropertyList[i].value = value;
                mStylePropertyList[i].priority = priority;
                return;
            }
        }
        StyleProperty prop = { property, value, priority };
        mStylePropertyList.push_back(prop);
    }
    void CSSStyleDeclaration::setPropertyValue(DOMString property, DOMString value)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(mStylePropertyList[i].id == property)
            {
                mStylePropertyList[i].value = value;
                break;
            }
        }
    }
    void CSSStyleDeclaration::setPropertyPriority(DOMString property, DOMString priority)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(mStylePropertyList[i].id == property)
            {
                mStylePropertyList[i].priority = priority;
                break;
            }
        }
    }
    DOMString CSSStyleDeclaration::removeProperty(DOMString property)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(mStylePropertyList[i].id == property)
            {
                DOMString prop = mStylePropertyList[i].value;
                mStylePropertyList.erase(mStylePropertyList.begin() + i);
                return prop;
            }
        }
        return DOMString("");
    }

    DOMString CSSStyleDeclaration::cssFloat()
    {
        return getPropertyValue("float");
    }

    CSSStyleDeclaration::StyleProperty& CSSStyleDeclaration::propertyItem(unsigned long index)
    {
        return mStylePropertyList[index];
    }

    void CSSStyleDeclaration::putProperty(DOMString property, DOMString value, DOMString priority)
    {
        for(unsigned i = 0; i < length(); i++)
        {
            if(mStylePropertyList[i].id == property)
            {
                if(priority == ImportantPriority)
                {
                    mStylePropertyList[i].value = value;
                    mStylePropertyList[i].priority = priority;
                }
                else if(mStylePropertyList[i].priority != ImportantPriority)
                {
                    if(priority.toLong() >= mStylePropertyList[i].priority.toLong())
                    {
                        mStylePropertyList[i].value = value;
                        mStylePropertyList[i].priority = priority;
                    }
                }
                return;
            }
        }
        StyleProperty prop = { property, value, priority };
        mStylePropertyList.push_back(prop);
    }

    void CSSStyleDeclaration::addProperty(StyleProperty prop)
    {
        mStylePropertyList.push_back(prop);
    }

    void CSSStyleDeclaration::clear()
    {
        mStylePropertyList.clear();
    }

    DOMString CSSStyleDeclaration::get(DOMString aProperty)
    {
        return getPropertyValue(aProperty.toUnderscore());
    }
    void CSSStyleDeclaration::set(DOMString aProperty, DOMString value)
    {
        setProperty(aProperty.toUnderscore(), value);
    }

}
