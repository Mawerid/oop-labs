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

    void menu();

    void cmd_loop(word::words *mass);
}

#endif