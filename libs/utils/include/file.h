/**
**********************************************************************************************************************************************************************************************************************************
* @file:	file.h
* @author:	Bilal Ben khali Bumedien
* @email:	bilalbenkhalibumedien@gmail.com
* @date:	24/10/2022 00:31:50
* @brief:	Class File
**********************************************************************************************************************************************************************************************************************************
**/

#ifndef __FILES__H__
#define __FILES__H__

#include "str.h"

#define BUF_SIZE 100

class File
{
public:
    enum Option
    {
        READ,       // Only read if just exist
        READWRITE,  // Only read and write if just exist
        WRITE,      // Write and read, and create if not exist
        APPEND      // Append to file, and create if not exist
    };

    File(const str &fileName);
    ~File();

    const str &fileName();
    const FILE* filePtr();

    bool open(const Option option = READ);
    bool close();

    str readFile();
    bool writeFile(const str &message);

    static str ReadFile(const str &fileName);
    static bool WriteFile(const str &fileName, const str &message);

private:
    FILE *file;
    str file_name;

    bool opened;

    const char* optionStr(const Option option);
};

#endif  //!__FILES__H__