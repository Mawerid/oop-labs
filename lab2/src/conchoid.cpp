#include <conchiod/conchoid.hpp>
#include <exception>
#include <math.h>
#include <string.h>

namespace conchoid
{
    //  constructors
    conchoid::conchoid(double a, double l) : a(a)
    {
        if (l == 0)
            throw std::exception("invalid l parameter");
        l = l;
    }

    //  setters
    conchoid &conchoid::set_a(double a0)
    {
        a = a0;
        return *this;
    }

    conchoid &conchoid::set_l(double l0)
    {
        if (l0 == 0)
            throw std::exception("invalid l parameter");
        l = l0;
        return *this;
    }

    //  other methods

    //  get y from x
    double conchoid::calc_y(const double x)
    {
        if (x == a)
            throw std::exception("illegal argument x");
        return (x / (x - a) * sqrt(pow(l, 2) - pow((x - a), 2)));
    }

    //  get r from theta (angle in radians)
    double conchoid::calc_r(const double theta)
    {
        if (cos(theta) == 0.0)
            throw std::exception("illegal argument theta");
        return (a / cos(theta) + l);
    }

    //  calculate radius of curvature at characteristic points
    double conchoid::rad_in_pont_A()
    {
        if (l == 0)
            throw std::exception("no point A");
        return (pow((l + a), 2) / l);
    }

    double conchoid::rad_in_pont_C()
    {
        if (l == 0)
            throw std::exception("no point C");
        return (pow((l - a), 2) / l);
    }

    double conchoid::rad_in_pont_O()
    {
        if (a == 0)
            throw std::exception("no point O");
        return (l * sqrt(pow(l, 2) - pow(l, 2)) / (2 * a));
    }

    //  calculate area of conchoid's loop
    double conchoid::area()
    {
        if (a == 0)
            return pow(l, 2) * M_PI;
        else if (a <= l)
            return (a * sqrt(pow(l, 2) - pow(a, 2)) -
                    2 * a * l * log((l + sqrt(pow(l, 2) - pow(a, 2))) / a) +
                    pow(l, 2) * acos(a / l));
        throw std::exception("loop does not exist");
    }

    //  calculate coordinates of inflection points
    point *conchoid::inf_points()
    {
        point *inf_p;
        if (a < l)
        {
            try
            {
                inf_p = new point;
            }
            catch (std::bad_alloc &ba)
            {
                throw std::exception(ba.what());
            }
            inf_p->x = 2.35 * a;
            inf_p->y = calc_y(inf_p->x);
        }
        else if (a == l)
        {
            try
            {
                inf_p = new point[3];
            }
            catch (std::bad_alloc &ba)
            {
                throw std::exception(ba.what());
            }
            inf_p[0].x = 0;
            inf_p[1].x = sqrt(3) * a;
            inf_p[2].x = (-1) * sqrt(3) * a;
            inf_p[0].y = calc_y(inf_p[0].x);
            inf_p[1].y = calc_y(inf_p[1].x);
            inf_p[2].y = calc_y(inf_p[2].x);
        }
        else
        {
            try
            {
                inf_p = new point[3];
            }
            catch (std::bad_alloc &ba)
            {
                throw std::exception(ba.what());
            }
            inf_p[0].x = 1.38 * a;
            inf_p[1].x = 0.57 * a;
            inf_p[2].x = (-1) * 1.9 * a;
            inf_p[0].y = calc_y(inf_p[0].x);
            inf_p[1].y = calc_y(inf_p[1].x);
            inf_p[2].y = calc_y(inf_p[2].x);
        }

        return inf_p;
    }

    //  return formula of conchoid
    char *conchoid::formula()
    {
        size_t len = 38;
        size_t size = 20;
        char num[size];
        sprintf_s(num, size, "%.2f", a);
        len += strlen(num);
        sprintf_s(num, size, "%.2f", l * l);
        len += strlen(num);

        char *form;
        try
        {
            form = new char[len];
        }
        catch (std::bad_alloc &ba)
        {
            throw std::exception(ba.what());
        }

        if (a == 0.0)
            sprintf_s(form, len, "x ^ 2 * (x ^ 2 + y ^ 2) = ");
        else
            sprintf_s(form, len, "(x - %.2f) ^ 2 * (x ^ 2 + y ^ 2) = ", a);

        size = strlen(form);
        if (l == 1.0)
            sprintf_s(form + size, len - size, "x ^ 2\n");
        else
            sprintf_s(form + size, len - size, "%.2f * x ^ 2\n", l*l);

        return form;
    }

} // namespace conchoid
