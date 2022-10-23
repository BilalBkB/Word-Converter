/**
**********************************************************************************************************************************************************************************************************************************
* @file:	date_time.h
* @author:	Bilal Ben khali Bumedien
* @email:	bilalbenkhalibumedien@gmail.com
* @date:	05/08/2022 15:19:09
* @brief:	Class DateTime
**********************************************************************************************************************************************************************************************************************************
**/

#ifndef __DATE_TIME__H__
#define __DATE_TIME__H__

// TODO: return seconds, month etc. operators- + etc

#include "str.h"
#include <time.h>

class DateTime
{
private:
    struct tm t;

public:
    DateTime();
    DateTime(const struct tm &t);
    ~DateTime();

    // TODO: with format
    str toString();

    static DateTime current();
};

#endif //!__DATE_TIME__H__