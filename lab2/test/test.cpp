#include <gtest/gtest.h>
#include <math.h>
#include "../include/conchoid.hpp"

TEST(ConchoidConstructor, DefaultConstructor)
{
    conchoid::conchoid tst;
    ASSERT_EQ(0.0, tst.get_a());
    ASSERT_EQ(1.0, tst.get_l());
}

TEST(ConchoidConstructor, InitConstructors)
{
    conchoid::conchoid tst;
    ASSERT_EQ(0.0, tst.get_a());
    ASSERT_EQ(1.0, tst.get_l());
    conchoid::conchoid tst_1(4.0);
    ASSERT_EQ(4.0, tst_1.get_a());
    ASSERT_EQ(1.0, tst_1.get_l());
    conchoid::conchoid tst_2(5.0, 2.0);
    ASSERT_EQ(5.0, tst_2.get_a());
    ASSERT_EQ(2.0, tst_2.get_l());
}

TEST(ConchoidConstructor, TestException)
{
    ASSERT_ANY_THROW(conchoid::conchoid(50, 0));
    ASSERT_ANY_THROW(conchoid::conchoid(-0.33, 0));
}

TEST(ConchoidMethods, Setters)
{
    conchoid::conchoid tst;
    tst.set_a(5.0);
    ASSERT_EQ(5.0, tst.get_a());
    tst.set_a(-18.20);
    ASSERT_EQ(-18.20, tst.get_a());
    tst.set_l(20.18);
    ASSERT_EQ(20.18, tst.get_l());
    tst.set_l(-16.04);
    ASSERT_EQ(-16.04, tst.get_l());
    ASSERT_ANY_THROW(tst.set_l(0));
}

TEST(ConchoidMethods, Area)
{
    conchoid::conchoid tst;
    conchoid::conchoid tst_1(1.0, 2.0);
    conchoid::conchoid tst_2(4.0, 2.0);
    conchoid::conchoid tst_3(2.0, 2.0);

    const double err = 0.00001;

    ASSERT_NEAR(M_PI, tst.area(), err);
    ASSERT_NEAR((sqrt(3) - 4 * log(2 + sqrt(3)) + 4 * M_PI / 3), tst_1.area(), err);
    ASSERT_ANY_THROW(tst_2.area());
    ASSERT_NEAR(0.0, tst_3.area(), err);
}

TEST(ConchoidMethods, Calc)
{
    conchoid::conchoid tst;
    conchoid::conchoid tst_1(1.0, 2.0);
    conchoid::conchoid tst_2(4.0, 2.0);
    conchoid::conchoid tst_3(2.0, 2.0);
    const double err = 0.00001;

    ASSERT_NEAR(0.0, tst.calc_y(1.0), err);
    ASSERT_NEAR(1.0, tst.calc_r(M_PI), err);

    ASSERT_ANY_THROW(tst_1.calc_y(1.0));
    ASSERT_NEAR(1.0, tst_1.calc_r(M_PI), err);

    ASSERT_NEAR((-1) * 3.0 * sqrt(3.0), tst_2.calc_y(3.0), err);
    ASSERT_NEAR((-1) * 2.0, tst_2.calc_r(M_PI), err);

    ASSERT_NEAR((-1) * sqrt(3.0), tst_3.calc_y(1.0), err);
    ASSERT_NEAR(0.0, tst_3.calc_r(M_PI), err);
}

TEST(ConchoidMethods, Radius)
{
    conchoid::conchoid tst;
    conchoid::conchoid tst_1(1.0, 2.0);
    conchoid::conchoid tst_2(4.0, 2.0);
    conchoid::conchoid tst_3(2.0, 2.0);
    const double err = 0.00001;

    ASSERT_NEAR(1.0, tst.rad_in_pont_A(), err);
    ASSERT_NEAR(1.0, tst.rad_in_pont_C(), err);
    ASSERT_ANY_THROW(tst.rad_in_pont_O());

    ASSERT_NEAR(4.5, tst_1.rad_in_pont_A(), err);
    ASSERT_NEAR(0.5, tst_1.rad_in_pont_C(), err);
    ASSERT_NEAR(sqrt(3.0), tst_1.rad_in_pont_O(), err);

    ASSERT_NEAR(18.0, tst_2.rad_in_pont_A(), err);
    ASSERT_NEAR(2.0, tst_2.rad_in_pont_C(), err);
    ASSERT_ANY_THROW(tst_2.rad_in_pont_O());

    ASSERT_NEAR(8.0, tst_3.rad_in_pont_A(), err);
    ASSERT_NEAR(0.0, tst_3.rad_in_pont_C(), err);
    ASSERT_NEAR(0.0, tst_3.rad_in_pont_O(), err);
}

TEST(ConchoidMethods, Points)
{
    conchoid::conchoid tst;
    double tmp;
    tmp = 0.0;
    const double err = 0.00001;

    ASSERT_NEAR(tmp, *tst.inf_points(), err);

    conchoid::conchoid tst_1(1.0, 2.0);
    double tmp_1;
    tmp_1 = 2.35;

    ASSERT_NEAR(tmp_1, *tst_1.inf_points(), err);

    conchoid::conchoid tst_2(4.0, 2.0);
    double tmp_2[3];
    tmp_2[0] = 1.38 * 4.0;
    tmp_2[1] = 0.57 * 4.0;
    tmp_2[2] = (-1) * 1.9 * 4.0;

    ASSERT_NEAR(tmp_2[0], tst_2.inf_points()[0], err);
    ASSERT_NEAR(tmp_2[1], tst_2.inf_points()[1], err);
    ASSERT_NEAR(tmp_2[2], tst_2.inf_points()[2], err);

    conchoid::conchoid tst_3(2.0, 2.0);
    double tmp_3[3];
    tmp_3[0] = 0.0;
    tmp_3[1] = sqrt(3) * 2.0;
    tmp_3[2] = (-1) * sqrt(3) * 2.0;

    ASSERT_NEAR(tmp_3[0], tst_3.inf_points()[0], err);
    ASSERT_NEAR(tmp_3[1], tst_3.inf_points()[1], err);
    ASSERT_NEAR(tmp_3[2], tst_3.inf_points()[2], err);
}

TEST(ConchoidMethods, Formula)
{
    conchoid::conchoid tst;
    conchoid::conchoid tst_1(1.0, 2.0);
    conchoid::conchoid tst_2(4.0, 2.0);
    conchoid::conchoid tst_3(2.0, 2.0);

    ASSERT_STREQ("x ^ 2 * (x ^ 2 + y ^ 2) = x ^ 2\n", tst.formula());
    ASSERT_STREQ("(x - 1.00) ^ 2 * (x ^ 2 + y ^ 2) = 4.00 * x ^ 2\n", tst_1.formula());
    ASSERT_STREQ("(x - 4.00) ^ 2 * (x ^ 2 + y ^ 2) = 4.00 * x ^ 2\n", tst_2.formula());
    ASSERT_STREQ("(x - 2.00) ^ 2 * (x ^ 2 + y ^ 2) = 4.00 * x ^ 2\n", tst_3.formula());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}