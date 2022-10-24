/**
**********************************************************************************************************************************************************************************************************************************
* @file:	str.h
* @author:	Bilal Ben khali Bumedien
* @email:	bilalbenkhalibumedien@gmail.com
* @date:	04/08/2022 12:55:47
* @brief:	Class str
**********************************************************************************************************************************************************************************************************************************
**/

#ifndef __STR__H__
#define __STR__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_READ 500

class StringList;

class str
{
private:
    char *textS = nullptr;

    void setText(const char *text, size_t length);

public:
    enum Order
    {
        ALFABETIC,
        REVERSE
    };

    str();
    ~str();
    str(const str &other);
    str(const char *text);
    str(const char &character);
    str(const int &number);
    str(const unsigned int &number);
    str(const float &number);

    str &operator=(const str &other);
    str &operator=(const char *text);
    str &operator=(const char &character);

    bool operator==(const str &other) const;
    bool operator!=(const str &other) const;
    bool operator<(const str &other) const;
    bool operator>(const str &other) const;

    template <typename Arg>
    const Arg& Argument(const Arg &arg)
    {
        return arg;
    }

    const char* Argument(const str &arg)
    {
        return arg.c_str();
    }

    template <typename... Args>
    str(const char *format, Args... args)
    {
        size_t length = snprintf(nullptr, 0, format, Argument(args)...);
        if (length < 0)
            return;

        textS = (char *)malloc(length + 1);
        snprintf(textS, length + 1, format, Argument(args)...);
        textS[length] = '\0';
    }

    static size_t length(const char *text);
    size_t length() const;

    const char *c_str() const;
    str append(const str &text);
    str append(const char &character);

    str substr(int initial, int final) const;
    // TODO: add capitalize (upper/lower) and indexOf

    int indexOf(const str &text, const Order &order = ALFABETIC) const;
    int closeFromAt(const int &start, const char &textFrom, const char &textAt) const;
    str remove(const str &text) const;
    str trim(const char delimiter = ' ') const;

    bool startWith(const str &text) const;
    bool endWith(const str &text) const;

    bool isEmpty() const;
    bool isNumber() const;

    StringList split(const char &delimiter = ' ') const;
    StringList split(const str &delimiter = " ") const;

};

#endif //!__STR__H__