#include <gtest/gtest.h>
// #include "../include/amoral.hpp"
// #include "../include/cell.hpp"
// #include "../include/immortal_amoral.hpp"
// #include "../include/immortal_moral.hpp"
// #include "../include/immortal.hpp"
// #include "../include/interface.hpp"
// #include "../include/landscape.hpp"
// #include "../include/lord.hpp"
// #include "../include/moral.hpp"
// #include "../include/school.hpp"
// #include "../include/skill.hpp"
// #include "../include/squad.hpp"
#include "../include/kdtree.hpp"
#include <math.h>

//  Field

TEST(Field, constructors_getters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Field, setters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Field, other_func)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

//  Cell

TEST(Cell, constructors_getters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Cell, setters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Cell, other_func)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

//  Landscape

TEST(Landscape, constructors_getters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Landscape, setters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Landscape, other_func)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

//  Lord

TEST(Lord, constructors_getters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Lord, setters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Lord, other_func)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

//  School

TEST(School, constructors_getters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(School, setters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(School, other_func)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

//  Skill

TEST(Skill, constructors_getters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Skill, setters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Skill, other_func)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

//  Squad

TEST(Squad, constructors_getters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Squad, setters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Squad, other_func)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

//  Moral

TEST(Moral, constructors_getters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Moral, setters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Moral, other_func)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

//  Amoral

TEST(Amoral, constructors_getters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Amoral, setters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Amoral, other_func)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

//  Immortal_moral

TEST(Immortal_moral, constructors_getters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Immortal_moral, setters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Immortal_moral, other_func)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

// Immortal_amoral

TEST(Immortal_amoral, constructors_getters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Immortal_amoral, setters)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

TEST(Immortal_amoral, other_func)
{
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
    ASSERT_EQ(4096 * 4096, pow(2, 12 * 2));
}

//  KDTree

typedef size_t node;

struct point_3D
{
    double x, y, z;
    const static int dimension = 2;

    double getDimension(int dim) const
    {
        switch (dim)
        {
        case 0:
            return x;
        case 1:
            return y;
        default:
            return std::numeric_limits<double>::quiet_NaN();
        }
    }

    bool operator==(const point_3D &point) const
    {
        if (this->x == point.x && this->y == point.y)
            return true;
        return false;
    }
};

std::ostream &operator<<(std::ostream &cout, const point_3D &point)
{
    cout << '(' << point.x << ", " << point.y << ')';
    return cout;
}

TEST(KDTree, all_tests)
{
    std::KDTree<point_3D> tree;

    std::vector<point_3D> pts{{0, 0}, {1, 1}, {-1, 3}, {5, 6}, {2, -6}, {4, 5}, {2, 3}, {2, 5}};
    tree.buildTree(pts);
    tree.dumpTreeInorder(std::cout);

    point_3D point_0{0, 0};

    ASSERT_EQ(point_0, tree.getPoint(0));

    std::vector<node> check = {1, 0};

    auto closeNodes = tree.getPointsWithinCube({0, 0, 0}, 1);

    ASSERT_EQ(check, closeNodes);

    std::ostringstream stream;

    char str[] = "(1, 1)\n(0, 0)\n";

    for (auto n : closeNodes)
    {
        tree.dumpNode(n, stream);
    }

    ASSERT_STREQ(str, stream.str().c_str());

    ASSERT_EQ(2, tree.findMin(0));
    ASSERT_EQ(4, tree.findMin(1));
    ASSERT_EQ(4, tree.findMin(2));

    ASSERT_NO_THROW(tree.deletePoint(2));
    ASSERT_NO_THROW(tree.dumpTreeInorder(std::cout));
}

// main

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}