/**
**********************************************************************************************************************************************************************************************************************************
* @file:	number.h
* @author:	Bilal Ben khali Bumedien
* @email:	bilalbenkhalibumedien@gmail.com
* @date:	24/10/2022 01:58:18
* @brief:	Class Number
**********************************************************************************************************************************************************************************************************************************
**/

#include "number.h"
#include "string_list.h"

const list<pairDigits> Number::plusDigitNames = {
    { "zero", 0},
    { "one", 1},
    { "two", 2},
    { "three", 3},
    { "four", 4},
    { "five", 5},
    { "six", 6},
    { "seven", 7},
    { "eight", 8},
    { "nine", 9},
    { "ten", 10},
    { "eleven", 11},
    { "twelve", 12},
    { "thirteen", 13},
    { "fourteen", 14},
    { "fifteen", 15},
    { "sixteen", 16},
    { "seventeen", 17},
    { "eigthteen", 18},
    { "nineteen", 19},
    { "twenty", 20},
    { "thirty", 30},
    { "forty", 40},
    { "fifty", 50},
    { "sixty", 60},
    { "seventy", 70},
    { "eighty", 80},
    { "ninety", 90}
};

const list<pairDigits> Number::productDigitNames = {
    { "hundred", 100},
    { "thousand", 1000},
    { "million", 1000000},
    { "billion", 1000000000}
};

Number::Number(const str &text)
{
    if (text.isEmpty())
        digits = 0;
}

// TODO: check incorrect secuence number of texts (for example: "one one one")
unsigned int Number::ToDigits(const str &text)
{
    unsigned int result = 0;

    if (text.isEmpty())
        return result;

    StringList words = text.split(' ');
    str *word;
    unsigned int last_number = 0;
    
    while (words.size())
    {
        word = words.removeAt(0);
        
        for (const pairDigits &digit : plusDigitNames)
            if (digit.first == *word)
            {
                result += digit.second;
                last_number = digit.second;
            }
        
        for (const pairDigits &digit : productDigitNames)
            if (digit.first == *word)
            {
                result -= last_number;
                result += (last_number * digit.second);
            }

        delete word;
    }

    return result;
}

bool Number::isNumericText(const str &text)
{
    for (const pairDigits &digit : plusDigitNames)
        if (digit.first == text)
            return true;

    for (const pairDigits &digit : productDigitNames)
        if (digit.first == text)
            return true;

    return false;
}
