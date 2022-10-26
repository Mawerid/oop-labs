#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <iostream>
#include <string.h>
#include "word.hpp"

namespace dialog
{
    /*
    func for right input (unsigned or char, for example)
    params:
    1 - input variable
    return:
    0 - OK
    1 - Bad input
    */
    template <class T>
    int getNum(T &var)
    {
        std::cin >> var;
        if (!std::cin.good())
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            return 1;
        }
        return 0;
    }

    /*
    func to avoid wrong input
    params:
    1 - message with inviting to write something
    2 - input variable
    return:
    None
    */
    template <class T>
    void input_num(const char *msg_print, T &num)
    {
        char msg[30] = "";
        do
        {
            std::cout << msg << std::endl;
            std::cout << msg_print;
            strcpy(msg, "You are wrong; repeat please!");
        } while (dialog::getNum(num));
    }

    /*
    function, that show menu message
    params:
    None
    return:
    None
    */
    void menu();

    /*
    main loop for menu
    params:
    1 - word massive as pointer
    return:
    None
    */
    void cmd_loop(word::words *mass);
}

#endif