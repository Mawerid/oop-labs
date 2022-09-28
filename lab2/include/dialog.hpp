#ifndef DIALOG_HPP
#define DIALOG_HPP

#include <iostream>
#include "conchoid.hpp"

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
    int input(double *a, double *l);
    void print(conchoid::conchoid &curve);
}

#endif