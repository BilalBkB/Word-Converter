/**
**********************************************************************************************************************************************************************************************************************************
* @file:	string_list.cpp
* @author:	Bilal Ben khali Bumedien
* @email:	bilalbenkhalibumedien@gmail.com
* @date:	05/08/2022 09:48:08
* @brief:	Class StringList
**********************************************************************************************************************************************************************************************************************************
**/

#include "string_list.h"

StringList::StringList() : ListGeneric<str>()
{
}

StringList::~StringList()
{
}

const str StringList::join(const str &delimiter)
{
    str text;
    if (size() == 0)
        return text;
    int i = 0;
    while (i < size() - 1)
        text = text.append(*at(i++)).append(delimiter);

    text = text.append(*at(i));

    return text;
}