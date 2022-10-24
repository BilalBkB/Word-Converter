/**
**********************************************************************************************************************************************************************************************************************************
* @file:	str.cpp
* @author:	Bilal Ben khali Bumedien
* @email:	bilalbenkhalibumedien@gmail.com
* @date:	24/10/2022 00:31:50
* @brief:	Class File
**********************************************************************************************************************************************************************************************************************************
**/

#include "file.h"

File::File(const str &fileName) : 
    file_name(fileName), file(nullptr), opened(false)
{
}

File::~File()
{
    close();
}

const str &File::fileName()
{
    return file_name;
}

const FILE* File::filePtr()
{
    return file;
}

const char* File::optionStr(const Option option)
{
    switch (option)
    {
        case READ:
            return "r";
            break;
        case READWRITE:
            return "r+";
            break;
        case WRITE:
            return "w+";
            break;
        case APPEND:
            return "a+";
            break;
        
        default:
            return "";
            break;
    }
}

bool File::open(const Option option)
{
    if (!opened || file == nullptr)
    {
        file = fopen(file_name.c_str(), optionStr(option));
    }

    if (file != nullptr)
        opened = true;
    else
    {
        printf("Failed opening file %s\n", file_name.c_str());
        opened = false;
    }

    return opened;
}

bool File::close()
{
    opened = file != nullptr && 
             fclose(file) != 0;

    if (!opened)
        file = nullptr;

    return !opened;
}

str File::readFile()
{
    str result;
    
    if(!open())
        return result;

    char buffer[BUF_SIZE];
    int size_readed = 0;

    while ((size_readed = fread(&buffer, sizeof(char), BUF_SIZE - 1, file)) != 0)
    {
        buffer[size_readed] = '\0';
        result = result.append(buffer);
    }

    return result;
}

bool File::writeFile(const str &message)
{
    if(!open(WRITE))
        return false;

    if (fprintf(file, "%s", message.c_str()) < 0)
    {
        printf("Failed writting in file %s \n", file_name.c_str());
        return false;
    }

    return true;
}

str File::ReadFile(const str &fileName)
{
    File file_to_read(fileName);

    return file_to_read.readFile();
}

bool File::WriteFile(const str &fileName, const str &message)
{
    File file_to_write(fileName);

    return file_to_write.writeFile(message);
}