#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <iostream>
#include <string.h>
#include "word.hpp"

namespace dialog
{
    /// @brief func for right input (unsigned or char, for example)
    /// @tparam T
    /// @param var
    /// @return 0 - OK or 1 - Bad input
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

    /// @brief func to avoid wrong input
    /// @tparam T
    /// @param msg_print
    /// @param num
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

    /// @brief function, that show menu message
    void menu();

    /// @brief main loop for menu
    /// @param mass
    void cmd_loop(word::words *mass);
}

#endif