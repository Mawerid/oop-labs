#ifndef CONCHOID_HPP
#define CONCHOID_HPP

#define LAB_VERSION "1.0.0"
#define VARIANT 3

namespace conchoid
{
    struct point
    {
        double x;
        double y;
        point(double x0 = 0, double y0 = 0) : x(x0), y(y0) {}
    };

    class conchoid
    {
    private:
        double a;
        double l;

    public:
        //  constructors
        conchoid(double a = 0, double l = 1); //    default - circle

        //  setters
        conchoid &set_a(double a0);
        conchoid &set_l(double l0);

        //  getters
        double get_a() const { return a; }
        double get_l() const { return l; }

        //  other methods

        //  get y from x
        double calc_y(double x);
        //  get r from theta (angle in radians)
        double calc_r(double theta);
        //  calculate radius of curvature at characteristic points
        double rad_in_pont_A();
        double rad_in_pont_C();
        double rad_in_pont_O();
        //  calculate area of conchoid's loop
        double area();
        //  calculate coordinates of inflection points
        point *inf_points();
        //  return formula of conchoid
        char *formula();
    };

}

#endif