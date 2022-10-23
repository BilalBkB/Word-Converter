/**
**********************************************************************************************************************************************************************************************************************************
* @file:	date_time.cpp
* @author:	Bilal Ben khali Bumedien
* @email:	bilalbenkhalibumedien@gmail.com
* @date:	05/08/2022 15:18:51
* @brief:	Class DateTime
**********************************************************************************************************************************************************************************************************************************
**/

#include "date_time.h"

DateTime::DateTime()
{
}

DateTime::DateTime(const struct tm &time)
{
    t = time;
}

DateTime::~DateTime()
{
}

str DateTime::toString()
{
    return str("%02d/%02d/%02d %02d:%02d:%02d", t.tm_mday, t.tm_mon, t.tm_year, t.tm_hour, t.tm_min, t.tm_sec);
}

DateTime DateTime::current()
{
    time_t t = time(NULL);
    struct tm timeM = *localtime(&t);
    return DateTime(timeM);
}