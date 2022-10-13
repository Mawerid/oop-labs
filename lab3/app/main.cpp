#include <iostream>
#include <string.h>
#include "../include/word.hpp"
#include "../include/dialog.hpp"

int main(int argc, char *argv[])
{
    word::words mass;
    word::words *tmp;
    char msg[30] = "";
    char str[80];
    char symb;
    unsigned cmd = 1;
    unsigned num = 0;

    dialog::menu();

    while (cmd != 0)
    {
        strcpy(msg, "");
        do
        {
            std::cout << msg << std::endl;
            std::cout << "Enter the command:    ";
            strcpy(msg, "You are wrong; repeat please!");
        } while (dialog::getNum(cmd));

        switch (cmd)
        {
        case 0:
            break;
        case 1:
            std::cout << "Enter the word, that you want to add: ";
            try
            {
                std::cin >> mass;
                // mass.input(std::cin);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
            std::cout << std::endl;
            break;
        case 2:
            strcpy(msg, "");
            do
            {
                std::cout << msg << std::endl;
                std::cout << "Enter the number of word in massive, that you want to delete: ";
                strcpy(msg, "You are wrong; repeat please!");
            } while (dialog::getNum(num));

            try
            {
                mass.del(num);
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
            break;
        case 3:
            std::cout << "Enter the word, that you want to search: ";
            std::cin >> str;
            num = mass.search(str);
            if (num == mass.get_count())
                std::cout << "No such word in massive." << std::endl;
            else
                std::cout << "The word " << str << "in massive can be found by number " << num << std::endl;

            break;
        case 4:
            strcpy(msg, "");
            do
            {
                std::cout << msg << std::endl;
                std::cout << "Enter the symbol:    ";
                strcpy(msg, "You are wrong; repeat please!");
            } while (dialog::getNum(symb));

            try
            {
                tmp = mass.first_symbol(symb);
                std::cout << "Here is massive: " << std::endl;
                std::cout << tmp;
                //  tmp->print(std::cout);
                delete tmp;
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }

            break;
        case 5:
            mass.sort();
            std::cout << mass;
            //  mass.print(std::cout);
            break;
        case 6:
            mass.clear();
            std::cout << "Massive has just cleared from all words" << std::endl;
            break;
        case 7:
            std::cout << mass;
            //  mass.print(std::cout);
            break;
        default:
            std::cout << "Unknown command, please, repeat your answer and check instruction." << std::endl;
            break;
        }
    }

    return 0;
}