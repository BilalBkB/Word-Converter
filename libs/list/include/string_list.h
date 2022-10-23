/**
**********************************************************************************************************************************************************************************************************************************
* @file:	string_list.h
* @author:	Bilal Ben khali Bumedien
* @email:	bilalbenkhalibumedien@gmail.com
* @date:	05/08/2022 09:47:53
* @brief:	Class StringList
**********************************************************************************************************************************************************************************************************************************
**/

#ifndef __STRING_LIST__H__
#define __STRING_LIST__H__

#include "list_generic.h"
#include "str.h"

class StringList : public ListGeneric<str>
{
private:
public:
    StringList();
    ~StringList();

    const str join(const str &delimiter = str());
};

#endif //!__STRING_LIST__H__