#include "../include/dialog.hpp"
#include "../include/conchoid.hpp"

namespace dialog
{
    void menu()
    {
        std::cout << std::endl;
        std::cout << "Here is Lab2 " << LAB_VERSION << " in variant " << VARIANT << std::endl;
        std::cout << "This program emulate curve named Conchoid of Nicomedes" << std::endl;
        std::cout << "------------------------------------------------" << std::endl
                  << std::endl;
    }

    int input(double *a, double *l)
    {
        std::cout << "Enter new parameters of curve (a and l): " << std::endl;
        do
        {
            if (getNum(*a))
            {
                std::cout << "You are wrong. Repeat, please!" << std::endl;
                continue;
            }
            else
                break;
        } while(true);
        do
        {
            if (getNum(*l))
            {
                std::cout << "You are wrong. Repeat, please!" << std::endl;
                continue;
            }
            else
                break;
        } while(true);

        return 0;
    }

    void print(conchoid::conchoid &curve)
    {
        std::cout << "Your conchoid is:" << std::endl;
        std::cout << curve.formula() << std::endl;
        try
        {
            std::cout << "area: " << curve.area() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            std::cout << "radius to point A: " << curve.rad_in_pont_A() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            std::cout << "radius to point C: " << curve.rad_in_pont_C() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            std::cout << "radius to point O: " << curve.rad_in_pont_O() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        double *pnt;
        pnt = curve.inf_points();

        if (!pnt)
        {
            std::cout << "there is no inflection points" << std::endl;
            return ;
        }

        std::cout << "inflection points: " << std::endl;

        if (curve.get_a() < curve.get_l())
        {
            std::cout << "( " << *pnt << " )" << std::endl;
            delete pnt;
        }
        else
        {
            std::cout << "( " << pnt[0] << " )" << std::endl;
            std::cout << "( " << pnt[1] << " )" << std::endl;
            std::cout << "( " << pnt[2] << " )" << std::endl;
            delete[] pnt;
        }
    }
}