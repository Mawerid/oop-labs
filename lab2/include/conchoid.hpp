#ifndef CONCHOID_HPP
#define CONCHOID_HPP

#define LAB_VERSION "1.0.0"
#define VARIANT 5

namespace conchoid
{
    class conchoid
    {
    private:
        double a;
        double l;

    public:
        //  constructors
        explicit conchoid(); //    default - circle
        explicit conchoid(double a, double l = 1.0);

        //  setters
        conchoid &set_a(double a0);
        conchoid &set_l(double l0);

        //  getters
        double get_a() const { return a; }
        double get_l() const { return l; }

        //  other methods

        //  get y from x
        double calc_y(double x) const;
        //  get r from theta (angle in radians)
        double calc_r(double theta) const;
        //  calculate radius of curvature at characteristic points
        double rad_in_pont_A() const;
        double rad_in_pont_C() const;
        double rad_in_pont_O() const;
        //  calculate area of conchoid's loop
        double area() const;
        //  calculate coordinates of inflection points
        double *inf_points() const;
        //  return formula of conchoid
        char *formula() const;
    };

}

#endif