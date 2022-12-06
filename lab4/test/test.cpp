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

TEST(Amoral, constructors_getters)
{
}

TEST(Amoral, setters)
{
    squad::Immortal_moral tmp;
    ASSERT_EQ(squad::immortal_moral_type::REAPER, tmp.get_type());
    tmp.set_type(squad::immortal_moral_type::MIMIC);
    ASSERT_EQ(squad::immortal_moral_type::MIMIC, tmp.get_type());
}

TEST(Amoral, other_func)
{
    squad::Immortal_moral tmp;
    ASSERT_EQ(squad::immortal_moral_type::REAPER, tmp.get_type());
    tmp.set_probability(1.0);
    tmp.set_max_health(constant::max_health::REAPER);
    tmp.set_health(constant::max_health::REAPER);
    ASSERT_EQ(constant::max_health::REAPER, tmp.get_health());
    tmp.set_health(constant::max_health::REAPER / 2);
    tmp.set_restore(constant::max_health::REAPER);
    tmp.heal();
    ASSERT_EQ(constant::max_health::REAPER, tmp.get_health());
}

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
    tmp.set_max_health(constant::max_health::REAPER);
    tmp.set_health(constant::max_health::REAPER);
    ASSERT_EQ(constant::max_health::REAPER, tmp.get_health());
    tmp.set_health(constant::max_health::REAPER / 2);
    tmp.set_restore(constant::max_health::REAPER);
    tmp.heal();
    ASSERT_EQ(constant::max_health::REAPER, tmp.get_health());
}

/*
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
    tmp.set_max_health(constant::max_health::COLOSSUS);
    tmp.set_health(constant::max_health::COLOSSUS);
    ASSERT_EQ(constant::max_health::COLOSSUS, tmp.get_health());
    tmp.set_health(constant::max_health::COLOSSUS / 2);
    tmp.set_restore(constant::max_health::COLOSSUS);
    tmp.heal();
    ASSERT_EQ(constant::max_health::COLOSSUS, tmp.get_health());
}*/

TEST(KDTree, all_tests)
{
    

    std::KDTree<simplePoint3> tree;
    std::vector<simplePoint3> pts{{0, 0, 0}, {1, 1, 1}, {-1, 3, 4}, {5, 6, 7}, {2, -6, 8}, {4, 5, -4}, {2, 3, 4}, {2, 5, 6}};
    tree.buildTree(pts);
    tree.dumpTreeInorder();

    std::cout << "searching near 0,0,0.1" << std::endl;
    auto closeNodes = tree.getPointsWithinCube({0, 0, 0.1}, 0.2);
    std::cout << "found" << std::endl;
    for (auto n : closeNodes)
    {
        tree.dumpNode(n);
    }

    std::cout << "searching near 0.5,0.5,0.5" << std::endl;
    closeNodes = tree.getPointsWithinCube({0.5, 0.5, 0.5}, 0.7);
    std::cout << "found" << std::endl;
    for (auto n : closeNodes)
    {
        tree.dumpNode(n);
    }

    std::cout << "min, x: " << std::endl;
    tree.dumpNode(tree.findMin(0));

    std::cout << "min, y: " << std::endl;
    tree.dumpNode(tree.findMin(1));
    std::cout << "min, z: " << std::endl;
    tree.dumpNode(tree.findMin(2));

    for (auto i = 0; i < pts.size() - 1; ++i)
    {
        std::cout << "deleting node " << i << std::endl;
        tree.deletePoint(i);
        tree.dumpTreeInorder();
    }

    std::cout << "inserting 2 points" << std::endl;
    tree.insertPoint({1, 4, 5});
    tree.dumpTreeInorder();
    tree.insertPoint({3, 8, 6});
    tree.dumpTreeInorder();
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}