#include "../include/conchoid.hpp"
#include "../include/dialog.hpp"

int main()
{
    conchoid::conchoid curve;
    int cmd = 1;
    double *a;
    double *l;
    a = new double;
    l = new double;
    *a = 0.0;
    *l = 1.0;
    double x_theta;

    dialog::menu();

    while (cmd)
    {
        dialog::print(curve);

        do
        {
            std::cout << "Enter x for calculate value y(x) or press ctrl+z to quit:" << std::endl;
            if (dialog::getNum(x_theta))
            {
                std::cout << "You are wrong. Repeat, please!" << std::endl;
                continue;
            }
            else
                break;
        } while (true);

        try
        {
            std::cout << "" << curve.calc_y(x_theta) << std::endl;
        }
        catch (std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }

        do
        {
            std::cout << "Enter theta for calculate value r(theta) or press ctrl+z to quit:" << std::endl;
            if (dialog::getNum(x_theta))
            {
                std::cout << "You are wrong. Repeat, please!" << std::endl;
                continue;
            }
            else
                break;
        } while (true);

        try
        {
            std::cout << "" << curve.calc_r(x_theta) << std::endl;
        }
        catch (std::exception &ex)
        {
            std::cout << ex.what() << std::endl;
        }

        if (dialog::input(a, l))
            cmd = 0;

        curve.set_a(*a);
        curve.set_l(*l);
    }

    delete a;
    delete l;
    return 0;
}