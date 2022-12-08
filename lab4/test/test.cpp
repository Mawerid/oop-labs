#include <gtest/gtest.h>
#include "../include/amoral.hpp"
#include "../include/cell.hpp"
#include "../include/immortal_amoral.hpp"
#include "../include/immortal_moral.hpp"
#include "../include/immortal.hpp"
#include "../include/interface.hpp"
#include "../include/landscape.hpp"
#include "../include/lord.hpp"
#include "../include/moral.hpp"
#include "../include/school.hpp"
#include "../include/skill.hpp"
#include "../include/squad.hpp"
#include "../include/kdtree.hpp"

//  Skill

TEST(Skill, constructors_getters)
{
}

TEST(Skill, setters)
{
}

TEST(Skill, other_func)
{
}

//  Squad

TEST(Squad, constructors_getters)
{
}

TEST(Squad, setters)
{
}

TEST(Squad, other_func)
{
}

//  Moral

TEST(Moral, constructors_getters)
{
}

TEST(Moral, setters)
{
}

TEST(Moral, other_func)
{
}

//  Amoral

TEST(Amoral, constructors_getters)
{
}

TEST(Amoral, setters)
{
}

TEST(Amoral, other_func)
{
}

//  Immortal_moral

TEST(Immortal_moral, constructors_getters)
{
    squad::Immortal_moral tmp;
    ASSERT_EQ(squad::immortal_moral_type::REAPER, tmp.get_type());
    squad::Immortal_moral tmp_1(squad::immortal_moral_type::MIMIC);
    ASSERT_EQ(squad::immortal_moral_type::MIMIC, tmp_1.get_type());
}

TEST(Immortal_moral, setters)
{
    squad::Immortal_moral tmp;
    ASSERT_EQ(squad::immortal_moral_type::REAPER, tmp.get_type());
    tmp.set_type(squad::immortal_moral_type::MIMIC);
    ASSERT_EQ(squad::immortal_moral_type::MIMIC, tmp.get_type());
}

TEST(Immortal_moral, other_func)
{
    squad::Immortal_moral tmp;
    ASSERT_EQ(squad::immortal_moral_type::REAPER, tmp.get_type());
    tmp.set_probability(1.0);
    tmp.set_max_health(constant::max_health::REAPER_MH);
    tmp.set_health(constant::max_health::REAPER_MH);
    ASSERT_EQ(constant::max_health::REAPER_MH, tmp.get_health());
    tmp.set_health(constant::max_health::REAPER_MH / 2);
    tmp.set_restore(constant::max_health::REAPER_MH);
    tmp.heal();
    ASSERT_EQ(constant::max_health::REAPER_MH, tmp.get_health());
}

// Immortal_amoral

TEST(Immortal_amoral, constructors_getters)
{
    squad::Immortal_amoral tmp;
    ASSERT_EQ(squad::immortal_amoral_type::COLOSSUS, tmp.get_type());
    squad::Immortal_amoral tmp_1(squad::immortal_amoral_type::DISRUPTOR);
    ASSERT_EQ(squad::immortal_amoral_type::DISRUPTOR, tmp_1.get_type());
}

TEST(Immortal_amoral, setters)
{
    squad::Immortal_amoral tmp;
    ASSERT_EQ(squad::immortal_amoral_type::COLOSSUS, tmp.get_type());
    tmp.set_type(squad::immortal_amoral_type::DISRUPTOR);
    ASSERT_EQ(squad::immortal_amoral_type::DISRUPTOR, tmp.get_type());
}

TEST(Immortal_amoral, other_func)
{
    squad::Immortal_amoral tmp;
    ASSERT_EQ(squad::immortal_amoral_type::COLOSSUS, tmp.get_type());
    tmp.set_probability(1.0);
    tmp.set_max_health(constant::max_health::COLOSSUS_MH);
    tmp.set_health(constant::max_health::COLOSSUS_MH);
    ASSERT_EQ(constant::max_health::COLOSSUS_MH, tmp.get_health());
    tmp.set_health(constant::max_health::COLOSSUS_MH / 2);
    tmp.set_restore(constant::max_health::COLOSSUS_MH);
    tmp.heal();
    ASSERT_EQ(constant::max_health::COLOSSUS_MH, tmp.get_health());
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
    ASSERT_ANY_THROW(tree.getPoint(2));
    ASSERT_NO_THROW(tree.dumpTreeInorder(std::cout));
}

// main

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}