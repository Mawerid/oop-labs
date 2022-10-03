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
}
