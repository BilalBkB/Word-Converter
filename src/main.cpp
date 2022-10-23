/**
**********************************************************************************************************************************************************************************************************************************
* @file:	main.cpp
* @author:	Bilal Ben khali Bumedien
* @email:	bilalbenkhalibumedien@gmail.com
* @date:	24/10/2022
* @brief:	class Main
**********************************************************************************************************************************************************************************************************************************
**/

#include "str.h"
#include "file.h"

str TranslateStrToDigits(const str message)
{
    return message;
}

int main(int argc, char* argv[])
{
    int status = 0;
    str input_file_name, output_file_name;

    if (argc != 3 && argc != 5)
    {
        status = 1;
    }
    else 
    {
        for(int i = 1; i < argc; i+=2)
        {
            if (str(argv[i]) == "-i")
            {
                input_file_name = argv[i+1];
            }
            else if(str(argv[i]) == "-o")
            {
                output_file_name = argv[i+1];
            }
        }

        if (input_file_name.isEmpty())
        {
            status = 2;
        }
        else
        {
            File input_file(input_file_name);
            File output_file(output_file_name);
            if (!input_file.open())
                status = 3;
            else if (!output_file_name.isEmpty() &&
                !output_file.open(File::WRITE))
            {
                status = 4;
            }
            else
            {
                str readed = input_file.readFile();
                str translated = TranslateStrToDigits(readed);

                if (!output_file_name.isEmpty())
                {
                    if (!output_file.writeFile(translated))
                        status = 5;
                }
                else
                {
                    printf("%s", translated.c_str());
                }
            }
            input_file.close();
            output_file.close();
        }
    }

    switch(status)
    {
        case 1:
            printf("Number of arguments are incorrect.\n");
            break;
        case 2:
            printf("Arguments are invalid.\n");
            break;
        case 3:
            printf("Input file '%s' can't open or founded.\n", 
                input_file_name.c_str());
            break;
        case 4:
            printf("Output file '%s' can't open or create.\n", 
                output_file_name.c_str());
            break;
        case 5:
            printf("Can't write result to outputfile '%s'.\n", 
                output_file_name.c_str());
            break;

    }
    if (status < 3 && status != 0)
    {
        printf("Called must be like: \n");
        printf("\tword_converter -i <input_file> [-o <output_file>]\n");
    }

    return status;
}
