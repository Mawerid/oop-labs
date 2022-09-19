#include <iostream>
#include "lab1.h"

using namespace lab1;

int main()
{

    //  print important thing about app
    start_msg();

    //  initialize some variables (matrix and it's size m and n)
    column *mass = nullptr;
    int m = 0, n = 0;
    line *vec_B = nullptr;

    //  load all matrix
    mass = input(m, n);

    //  check for errors
    if (!mass)
    {
        std::cout << "Invalid data" << std::endl;
        return 1;
    }

    //  calculate result vector and check for errors
    if (calc_vec(*mass, vec_B, m))
    {
        std::cout << "Error in allocate memory" << std::endl;
        erase(mass);
        return 1;
    }

    if (!vec_B)
    {
        std::cout << "Calculation error" << std::endl;
        return 1;
    }

    //  print matrix and vector in console
    output("Soursed matrix", *mass, *vec_B);
    //  clear matrix and vector
    erase(mass);
    erase(vec_B);

    return 0;
}