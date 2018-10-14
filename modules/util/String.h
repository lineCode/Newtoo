#pragma once

#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>

namespace Newtoo
{

    struct String // обертка над std::string
    {

    private:

        std::string data_;

    public:

        String() {}
        String(const char str) : data_(std::to_string(str)) {}
        String(const char str[]) : data_(str) {}
        String(const String& str) : data_(str.data_) {}
        String(const std::string str) : data_(str) {}
        ~String() {}

        char& operator [](const unsigned long index)
        {
            return data_[index];
        }
        void operator +=(const String str)
        {
            data_ += str.data_;
        }
        void operator +=(const char str[])
        {
            data_ += std::string(str);
        }
        void operator +=(const char str)
        {
            std::string c;
            c = c + str;
            data_ += c;
        }
        void operator =(const String str)
        {
            data_ = str.data_;
        }
        void operator =(const char str[])
        {
            data_ = std::string(str);
        }
        bool operator ==(const char str[])
        {
            return this->equals(str);
        }
        bool operator ==(const String str)
        {
            return this->equals(str);
        }
        bool operator !=(const char str[])
        {
            return this->equals(str) == false;
        }
        bool operator !=(const String str)
        {
            return this->equals(str) == false;
        }
        String operator +(String str)
        {
            return this->concat(str);
        }
        String operator +(const char str[])
        {
            return this->concat(str);
        }
        char& at(const unsigned long index)
        {
            return data_[index];
        }
        char& item(const unsigned long index)
        {
            return data_[index];
        }
        bool equals(const String str)
        {
            return data_ == str.data_;
        }
        bool equals(const char str[])
        {
            return data_ == std::string(str);
        }
        //String& toLower();
        //String& toUpper();
        String dublicate()
        {
            return String(std::string(data_));
        }
        String concat(String str)
        {
            return String(data_ + str.data_);
        }
        String concat(const char str[])
        {
            return String(data_ + std::string(str));
        }
        String append_(const String str)
        {
            return this->append(str);
        }
        String append_(const char str[])
        {
            return this->append(str);
        }
        String append_(const char str)
        {
            return this->append(str);
        }
        String append(const String str)
        {
            return String(data_ + str.data_);
        }
        String append(const char str[])
        {
            return String(data_ + std::string(str));
        }
        String append(const char str)
        {
            std::string c = data_;
            c = c + str;
            return String(c);
        }
        void prependCharToThis(const char str)
        {
            std::string c;
            c = c + str;
            data_ = c + data_;
        }
        String substring(const unsigned long index, const unsigned long length)
        {
            return String(data_.substr(index, length));
        }
        String cut(const unsigned long index, const unsigned long length)
        {
            return this->erase(index, length);
        }
        String erase(const unsigned long index, const unsigned long length)
        {
            std::string ret = data_;
            ret.erase(index, length);
            return String(ret);
        }
        void eraseThis(const unsigned long index, const unsigned long length)
        {
            data_.erase(index, length);
        }
        String replace(String str1, String str2)
        {
            return data_.replace(data_.find(str1.data_), str1.data_.length(), str2.data_);
        }
        String replace(const char str1[], String str2)
        {
            std::string str1s = std::string(str1);
            return data_.replace(data_.find(str1s), str1s.length(), str2.data_);
        }
        String replace(String str1, const char str2[])
        {
            return data_.replace(data_.find(str1.data_), str1.data_.length(), std::string(str2));
        }
        String replace(const char str1[], const char str2[])
        {
            std::string str1s = std::string(str1);
            return data_.replace(data_.find(str1s), str1s.length(), std::string(str2));
        }
        String replace(const unsigned long index, const unsigned long length, String str)
        {
            return data_.replace(index, length, str.data_);
        }
        String replace(const unsigned long index, const unsigned long length, const char str[])
        {
            return data_.replace(index, length, std::string(str));
        }
        bool startsWith(String str)
        {
            unsigned long len = str.data_.length();
            if(len > data_.size())
                return false;
            std::string piece = data_.substr(0, len);
            return piece == str.data_;
        }
        bool startsWith(const char str[])
        {
            unsigned long len = strlen(str);
            if(len > data_.size())
                return false;
            std::string piece = data_.substr(0, len);
            return piece == str;
        }
        bool endsWith(String str)
        {
            unsigned long len = str.data_.length();
            if(len > data_.size())
                return false;
            std::string piece = data_.substr(data_.length() - str.data_.length(), str.data_.length());
            return piece == str.data_;
        }
        bool endsWith(const char str[])
        {
            unsigned long len = strlen(str);
            if(len > data_.size())
                return false;
            std::string piece = data_.substr(data_.length() - len, len);
            return piece == str;
        }
        bool startsWithChar(const char chr)
        {
            return data_[0] == chr;
        }
        bool endsWithChar(const char chr)
        {
            return data_[data_.length() - 1] == chr;
        }
        unsigned long indexOf(String str)
        {
            return data_.find(str.data_);
        }
        unsigned long indexOf(const char str[])
        {
            return data_.find(str);
        }
        unsigned long indexOfChar(const char str, unsigned long startsAt = 0)
        {
            return data_.find(str, startsAt);
        }

        void* find(String str)
        {
            void* ret = strstr(this->data_.c_str(), str.data_.c_str());
            return ret;
        }
        void* find(const char str[])
        {
            return strstr(this->data_.c_str(), str);
        }
        void* findChar(const char str)
        {
            return strchr(this->data_.c_str(), str);
        }
        bool has(String str)
        {
            return data_.find(str.data_) != std::string::npos;
        }
        bool has(const char str[])
        {
            return find(str) != NULL;
        }
        bool contains(String str)
        {
            return contains(str);
        }
        bool contains(const char str[])
        {
            return contains(str);
        }
        bool hasChar(const char str, unsigned long startsAt)
        {
            for(unsigned i = 0; i < data_.size(); i++) {
                if(i >= startsAt)
                {
                    if(data_[i] == str)
                        return true;
                }
            }
            return false;
        }
        bool hasChar(const char str)
        {
            for(unsigned i = 0; i < data_.size(); i++) {
                if(data_[i] == str)
                    return true;
            }
            return false;
        }
        bool hasCharReverse(const char str)
        {
            for(signed i = data_.size() - 1; i > -1; i++) {
                if(data_[i] == str)
                    return true;
            }
            return false;
        }
        unsigned long size()
        {
            return data_.length();
        }
        unsigned long length()
        {
            return data_.length();
        }
        unsigned long capacity()
        {
            return data_.capacity();
        }
        unsigned long weight()
        {
            return data_.length() * sizeof(char);
        }
        bool empty()
        {
            return data_.empty();
        }
        void clear()
        {
            data_.clear();
        }
        const char * raw()
        {
            return data_.c_str();
        }
        String toLower_()
        {
            std::string ret = data_;
            std::transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
            return String(ret);
        }
        short toShort()
        {
            return (short)strtol(data_.c_str(), NULL, 10);
        }
        int toInt()
        {
            return (int)strtol(data_.c_str(), NULL, 10);
        }
        long toLong()
        {
            return strtol(data_.c_str(), NULL, 10);
        }
        float toFloat()
        {
            return strtof(data_.c_str(), NULL);
        }
        double toDouble()
        {
            return strtod(data_.c_str(), NULL);
        }

        #define m_from(format)			\
        char buff[128];					\
        sprintf(buff, format, value);	\
        data_ = std::string(buff);

        void fromShort(short value)
        {
            m_from("%i");
        }
        void fromInt(int value)
        {
            m_from("%i");
        }
        void fromLong(long value)
        {
            m_from("%li");
        }
        void fromFloat(float value)
        {
            m_from("%f");
        }
        void fromDouble(double value)
        {
            m_from("%f");
        }

    #undef m_from

        void print()
        {
            std::cout << data_;
        }

#define UNDERSCORE_SPLIT_CHAR '_'

        String toUnderscore()
        {
            std::string c = data_;
            unsigned i = 0;
            while(true)
            {
                if(i >= c.size())
                    break;

                if(isupper(c[i]))
                {
                    char lower = tolower(c[i]);
                    std::string next = c.substr(i + 1, c.size() - i - 1);
                    c = c.substr(0, i);
                    c = c + UNDERSCORE_SPLIT_CHAR;
                    c = c + lower;
                    c = c + next;
                }
                i++;
            }
            return String(c);
        }
    };

}

#undef m_check_temporary
#undef m_check_temporary_str

