#include "../include/dialog.hpp"

namespace dialog
{
    void menu()
    {
        std::cout << std::endl;
        std::cout << "Here is Lab3 " << LAB_VERSION << " in variant " << VARIANT << std::endl;
        std::cout << "This program woks with massive of words" << std::endl;
        std::cout << "------------------------------------------------" << std::endl
                  << std::endl;
        std::cout << "Enter:" << std::endl;
        std::cout << "0 - exit the programm" << std::endl;
        std::cout << "1 - add new element" << std::endl;
        std::cout << "2 - delete some word by number" << std::endl;
        std::cout << "3 - search for word" << std::endl;
        std::cout << "4 - see all words starts with entered symbol" << std::endl;
        std::cout << "5 - sort and show massive" << std::endl;
        std::cout << "6 - clear massive" << std::endl;
        std::cout << "7 - show massive of words" << std::endl;
        std::cout << "------------------------------------------------" << std::endl
                  << std::endl;
    }

    void cmd_loop(word::words *mass)
    {
        word::words *tmp;
        char msg[30] = "";
        char str[80];
        char symb;
        unsigned cmd = 1;
        unsigned num = 0;

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
                    std::cin >> *mass;
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
                    mass->del(num);
                }
                catch (const std::exception &e)
                {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 3:
                std::cout << "Enter the word, that you want to search: ";
                std::cin >> str;
                num = mass->search(str);
                if (num == mass->get_count())
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
                    tmp = mass->first_symbol(symb);
                    std::cout << "Here is massive: " << std::endl;
                    std::cout << *tmp;
                    //  tmp->print(std::cout);
                    delete tmp;
                }
                catch (const std::exception &e)
                {
                    std::cout << e.what() << std::endl;
                }

                break;
            case 5:
                mass->sort();
                std::cout << *mass;
                //  mass.print(std::cout);
                break;
            case 6:
                mass->clear();
                std::cout << "Massive has just cleared from all words" << std::endl;
                break;
            case 7:
                std::cout << *mass;
                //  mass.print(std::cout);
                break;
            default:
                std::cout << "Unknown command, please, repeat your answer and check instruction." << std::endl;
                break;
            }
        }
    }
}