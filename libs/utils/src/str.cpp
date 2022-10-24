/**
**********************************************************************************************************************************************************************************************************************************
* @file:	str.cpp
* @author:	Bilal Ben khali Bumedien
* @email:	bilalbenkhalibumedien@gmail.com
* @date:	04/08/2022 23:12:57
* @brief:	Class str
**********************************************************************************************************************************************************************************************************************************
**/

#include "str.h"
#include "string_list.h"

str::str()
{
    textS = new char();
}

str::~str()
{
    if (textS != nullptr)
        delete textS;
}

str::str(const str &other)
{
    textS = nullptr;

    *this = other;
}

str::str(const char *text)
{
    textS = nullptr;

    *this = text;
}

str::str(const char &text)
{
    textS = nullptr;

    *this = text;
}

str::str(const int &number)
{
    *this = str("%d", number);
}

str::str(const unsigned int &number)
{
    *this = str("%u", number);
}

str::str(const float &number)
{
    *this = str("%f", number);
}

str &str::operator=(const str &other)
{
    *this = other.textS;
    return *this;
}

void str::setText(const char *text, size_t length)
{
    if (textS != nullptr)
        delete textS;

    textS = (char *)malloc(length + 1);
    memcpy(textS, text, length + 1);
    textS[length] = '\0';
}

str &str::operator=(const char *text)
{
    if (text != nullptr)
        setText(text, length(text));

    return *this;
}

str &str::operator=(const char &character)
{
    if (textS != nullptr)
        delete textS;

    textS = (char *)malloc(2);

    textS[0] = character;
    textS[1] = '\0';

    return *this;
}

bool str::operator==(const str &other) const
{
    if (length() != other.length())
        return false;

    for (int i = 0; i < length(); i++)
        if (textS[i] != other.textS[i])
            return false;

    return true;
}

bool str::operator!=(const str &other) const
{
    return !(*this == other);
}

bool str::operator<(const str &other) const
{
    int i;
    for (i = 0; i < length() && i < other.length(); i++)
        if (textS[i] > other.textS[i])
            return false;

    if (i >= length() && i < other.length())
        return false;

    return true;
}

bool str::operator>(const str &other) const
{
    return !(*this > other);
}

size_t str::length(const char *text)
{
    if (!text)
        return 0;

    int size = 0;

    while (text[size] != '\0')
    {
        size++;
    }

    return size;
}

size_t str::length() const
{
    return length(textS);
}

const char *str::c_str() const
{
    return textS;
}

str str::append(const str &text)
{
    return str("%s%s", textS, text.c_str());
}

str str::append(const char &character)
{
    return append(str(character));
}

str str::substr(int initial, int final) const
{
    if (isEmpty() || length() < initial || length() < final)
        return str();
    size_t size = final - initial;
    char *text = (char *)malloc(size + 1);
    memcpy(text, (textS + initial), size);
    text[size] = '\0';
    return str(text);
}

int str::indexOf(const str &text, const Order &order) const
{
    if (text.length() == 0)
        return -1;

    int index = 0;

    int size = length();
    int size_text = text.length();

    if (order == ALFABETIC)
    {
        while (index < size && substr(index, size_text + index) != text)
            index++;
        if (index >= size)
            index = -1;
    }
    else
    {
        index = size - 1;
        while (index >= 0 && substr(index, size_text + index) != text)
            index--;
    }

    return index;
}


// TODO: with str like other methods
int str::closeFromAt(const int &start, const char &textFrom, const char &textAt) const
{
    int size = length();
    int foundFrom = 0;
    for (int i = start; i < size; i++)
    {
        if (textS[i] == textFrom)
            foundFrom++;
        else if (textS[i] == textAt)
            foundFrom--;

        if (foundFrom == 0)
            return i;
    }

    return -1;
}

str str::remove(const str &text) const
{
    str to_remove = *this;
    int index_found = to_remove.indexOf(text);
    while (index_found != -1)
    {
        str start = to_remove.substr(0, index_found);
        str end = to_remove.substr(index_found + text.length(), to_remove.length());
        to_remove = start.append(end);
        index_found = to_remove.indexOf(text);
    }
    return to_remove;
}

str str::trim(const char delimiter) const
{
    str result = *this;

    while (result.length() > 0 && result.textS[0] == delimiter)
        result = result.substr(1, result.length());

    while (result.length() > 0 && result.textS[result.length() - 1] == delimiter)
        result = result.substr(0, result.length() - 1);

    return result;
}

bool str::startWith(const str &text) const
{
    return text.length() > 0 && substr(0, text.length()) == text;
}

bool str::endWith(const str &text) const
{
    return text.length() > 0 && substr(length() - text.length(), length()) == text;
}

bool str::isEmpty() const
{
    return length() == 0;
}

bool str::isNumber() const
{
    int size = length();

    for (int i = 0; i < length(); i++)
        // Check if is all text are digit or dot
        if ((textS[i] < 0x30 || textS[i] > 0x39) && textS[i] != 0x2E)
            return false;

    return true;
}

StringList str::split(const char &delimiter) const
{
    StringList list;

    str *text = new str();
    size_t size = length();
    for (int i = 0; i < size; i++)
    {
        if (delimiter != textS[i])
        {
            *text = text->append(textS[i]);
        }
        else
        {
            list.insert(text);
            text = new str();
        }
    }

    if (text->length() > 0)
        list.insert(text);
    else
        delete text;

    return list;
}

StringList str::split(const str &delimiter) const
{
    StringList list;
    size_t delimiter_size = delimiter.length();

    if (delimiter_size == 0)
    {
        list.insert(new str(textS));
        return list;
    }

    size_t size = length();
    int last_index = 0;
    int i = 0;
    str sub;
    while (i <= size - delimiter_size)
    {
        if (substr(i, i + delimiter_size) == delimiter && last_index != i)
        {
            list.insert(new str(substr(last_index, i).trim()));
            i += delimiter_size;
            last_index = i;
        }
        else
            i++;
    }
    if (i != last_index)
        list.insert(new str(substr(last_index, i).trim()));

    return list;
}