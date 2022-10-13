#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <iostream>
#include <string.h>
#include "word.hpp"

namespace dialog
{
    template <class T>
    int getNum(T &a)
    {
        std::cin >> a;
        if (!std::cin.good())
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            return 1;
        }
        return 0;
    }

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

    void menu();

    void cmd_loop(word::words *mass);
}

#endif