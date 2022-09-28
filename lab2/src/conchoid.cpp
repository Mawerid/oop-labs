#include "../include/conchoid.hpp"
#include <stdexcept>
#include <math.h>
#include <string.h>

namespace conchoid
{
    //  constructors
    conchoid::conchoid() : a(0.0), l(1.0) {}

    conchoid::conchoid(double a, double l) : a(a)
    {
        if (l == 0.0)
            throw std::invalid_argument("invalid l parameter");
        this->l = l;
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
            throw std::invalid_argument("invalid l parameter");
        l = l0;
        return *this;
    }

    //  other methods

    //  get y from x
    double conchoid::calc_y(const double x) const
    {
        if (x == a || abs(l) < abs(x - a))
            throw std::invalid_argument("illegal argument x");
        return (x / (x - a) * sqrt(pow(l, 2) - pow((x - a), 2)));
    }

    //  get r from theta (angle in radians)
    double conchoid::calc_r(const double theta) const
    {
        if (cos(theta) == 0.0)
            throw std::invalid_argument("illegal argument theta");
        return (a / cos(theta) + l);
    }

    //  calculate radius of curvature at characteristic points
    double conchoid::rad_in_pont_A() const
    {
        if (l == 0)
            throw std::invalid_argument("no point A");
        return (pow((l + a), 2) / l);
    }

    double conchoid::rad_in_pont_C() const
    {
        if (l == 0)
            throw std::invalid_argument("no point C");
        return (pow((l - a), 2) / l);
    }

    double conchoid::rad_in_pont_O() const
    {
        if (a == 0 || (abs(a) > abs(l)))
            throw std::invalid_argument("no point O");
        return (l * sqrt(pow(l, 2) - pow(a, 2)) / (2 * a));
    }

    //  calculate area of conchoid's loop
    double conchoid::area() const
    {
        if (a == 0)
            return pow(l, 2) * M_PI;
        else if (a <= l)
            return (a * sqrt(pow(l, 2) - pow(a, 2)) -
                    2 * a * l * log((l + sqrt(pow(l, 2) - pow(a, 2))) / a) +
                    pow(l, 2) * acos(a / l));
        throw std::invalid_argument("loop does not exist");
    }

    //  calculate coordinates of inflection points
    double *conchoid::inf_points() const
    {
        if (a < l)
        {
            double *inf_p;
            inf_p = new double;
            *inf_p = 2.35 * a;

            return inf_p;
        }
        else if (a == l)
        {
            double *inf_p;
            inf_p = new double[3];
            inf_p[0] = 0;
            inf_p[1] = sqrt(3) * a;
            inf_p[2] = (-1) * sqrt(3) * a;

            return inf_p;
        }
        else
        {
            double *inf_p = new double[3];
            inf_p[0] = 1.38 * a;
            inf_p[1] = 0.57 * a;
            inf_p[2] = (-1) * 1.9 * a;

            return inf_p;
        }
    }

    //  return formula of conchoid
    char *conchoid::formula() const
    {
        size_t len = 41;
        size_t size = 20;
        char num[size];
        snprintf(num, size, "%.2f", a);
        len += strlen(num);
        snprintf(num, size, "%.2f", l * l);
        len += strlen(num);

        char *form;
        form = new char[len];

        if (a == 0.0)
            snprintf(form, len, "x ^ 2 * (x ^ 2 + y ^ 2) = ");
        else
            snprintf(form, len, "(x - %.2f) ^ 2 * (x ^ 2 + y ^ 2) = ", a);
        size = strlen(form);

        if (l == 1.0)
            snprintf(form + size, len - size, "x ^ 2\n");
        else
            snprintf(form + size, len - size, "%.2f * x ^ 2\n", l * l);

        return form;
    }

} // namespace conchoid
