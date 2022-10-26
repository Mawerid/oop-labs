#include "../include/dialog.hpp"

namespace dialog
{
    /*
    function, that show menu message
    params:
    None
    return:
    None
    */
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

    /*
    main loop for menu
    params:
    1 - word massive as pointer
    return:
    None
    */
    void cmd_loop(word::words *mass)
    {
        word::words *tmp;
        char str[81];
        char symb;
        unsigned cmd = 1;
        unsigned num = 0;

        while (cmd != 0)
        {
            input_num("Enter the command:    ", cmd);

            std::cin.clear();
            try
            {
                switch (cmd)
                {
                case 0:
                    break;
                case 1:
                    std::cout << "Enter the word, that you want to add: ";
                    std::cin >> *mass;
                    // mass.input(std::cin);
                    std::cout << std::endl;
                    std::cin.clear();
                    break;
                case 2:
                    input_num("Enter the number of word in massive, that you want to delete: ", num);
                    mass->del(num);
                    std::cin.clear();
                    break;
                case 3:
                    std::cout << "Enter the word, that you want to search: ";
                    std::cin >> str;
                    num = mass->search(str);
                    if (num == mass->get_size())
                        std::cout << "No such word in massive." << std::endl;
                    else
                        std::cout << "The word " << str << " in massive can be found by number " << num << std::endl;
                    std::cin.clear();
                    break;
                case 4:
                    input_num("Enter the symbol:    ", symb);
                    tmp = mass->first_symbol(symb);
                    std::cout << "Here is massive: " << std::endl;
                    std::cout << *tmp;
                    //  tmp->print(std::cout);
                    delete tmp;
                    std::cin.clear();
                    break;
                case 5:
                    mass->sort();
                    std::cout << *mass;
                    //  mass.print(std::cout);
                    std::cin.clear();
                    break;
                case 6:
                    mass->clear();
                    std::cout << "Massive has just cleared from all words" << std::endl;
                    std::cin.clear();
                    break;
                case 7:
                    std::cout << *mass;
                    //  mass.print(std::cout);
                    std::cin.clear();
                    break;
                default:
                    std::cout << "Unknown command, please, repeat your answer and check instruction." << std::endl;
                    break;
                }
            }
            catch (const std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
}