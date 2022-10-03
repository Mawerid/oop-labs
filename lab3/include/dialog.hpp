#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <iostream>
#include "word.hpp"

namespace dialog
{
    template <class T>
    int getNum(T &a)
    {
        std::cin >> a;
        if (!std::cin.good())
        {
            return 1;
        }
        return 0;
    }

    void menu();
}

#endif