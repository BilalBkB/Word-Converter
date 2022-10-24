/**
**********************************************************************************************************************************************************************************************************************************
* @file:	number.h
* @author:	Bilal Ben khali Bumedien
* @email:	bilalbenkhalibumedien@gmail.com
* @date:	24/10/2022 01:58:18
* @brief:	Class Number
**********************************************************************************************************************************************************************************************************************************
**/

#ifndef __NUMBER__H__
#define __NUMBER__H__

#include "str.h"
#include <list>

using namespace std;

typedef pair<str, unsigned int> pairDigits;

class Number
{
private:
    unsigned int digits;

    static const list<pairDigits> plusDigitNames;
    static const list<pairDigits> productDigitNames;

public:
    Number(const str &text = str());
    ~Number();

    static unsigned int ToDigits(const str &text);
    static bool isNumericText(const str &text);
};

#endif  //!__NUMBER__H__