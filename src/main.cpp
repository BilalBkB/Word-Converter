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
#include "number.h"
#include "string_list.h"

str TranslateStrToDigits(const str &message)
{
    StringList replaced;// = message;

    StringList sentences = message.split('.');

    bool is_numeric;
    str* to_replace;
    StringList words;
    str* word;
    StringList wordsResult;
    str digitText;
    str append_characters;
    while (sentences.size())
    {
        to_replace = sentences.removeAt(0);

        words = to_replace->split(' ');
        delete to_replace;
        
        while (words.size())
        {
            word = words.removeAt(0);
            is_numeric = Number::isNumericText(*word);
            if (is_numeric)
            {
                digitText = str("%s %s", digitText, *word);
            }
            else if (*word != '\n' && *word != '\t')
            {
                if(!digitText.isEmpty())
                {
                    wordsResult.insert(new str(Number::ToDigits(digitText.trim())));
                    digitText = str();
                }
                
                if (!append_characters.isEmpty())
                {
                    wordsResult.insert(new str(append_characters.trim()));
                    append_characters = str();
                }
                wordsResult.insert(new str(*word));
            }
            else
            {
                append_characters = str("%s %s", append_characters, *word);
            }
            delete word;
        }

        replaced.insert(new str(wordsResult.join(' ')));
        wordsResult.clean();
    }

    str result = replaced.join('.');
    replaced.clean();
    sentences.clean();
    wordsResult.clean();
    words.clean();

    return result;
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
                
                printf("%s\n", translated.c_str());
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
