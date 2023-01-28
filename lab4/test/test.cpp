#include <gtest/gtest.h>
#include <math.h>

#include "../include/kdtree.hpp"
#include "../include/landscape.hpp"

TEST(Cell, constructors_getters) {
    field::Point tmp;
    ASSERT_EQ(0, tmp.get_x());
    ASSERT_EQ(0, tmp.get_y());

    field::Point tmp_1(2, 3);
    ASSERT_EQ(2, tmp_1.get_x());
    ASSERT_EQ(3, tmp_1.get_y());

    field::Cell cell(tmp, field::cell_type::FREE, nullptr);

    ASSERT_EQ(tmp, cell.get_coordinates());
    ASSERT_EQ(field::cell_type::FREE, cell.get_type());
    ASSERT_EQ(nullptr, cell.get_squad());
}

TEST(Cell, setters) {
    field::Point tmp;
    ASSERT_EQ(0, tmp.get_x());
    ASSERT_EQ(0, tmp.get_y());

    field::Cell cell(tmp, field::cell_type::FREE, nullptr);

    ASSERT_EQ(tmp, cell.get_coordinates());
    ASSERT_EQ(field::cell_type::FREE, cell.get_type());
    ASSERT_EQ(nullptr, cell.get_squad());

    field::Point tmp_1(2, 3);
    ASSERT_EQ(2, tmp_1.get_x());
    ASSERT_EQ(3, tmp_1.get_y());

    cell.set_coordinates(tmp_1);
    cell.set_type(field::cell_type::BUSY);

    ASSERT_EQ(tmp_1, cell.get_coordinates());
    ASSERT_EQ(field::cell_type::BUSY, cell.get_type());
}

TEST(Cell, other_func) {
    field::Point tmp;
    ASSERT_EQ(0, tmp.get_x());
    ASSERT_EQ(0, tmp.get_y());

    field::Point tmp_1(3, 4);
    ASSERT_EQ(3, tmp_1.get_x());
    ASSERT_EQ(4, tmp_1.get_y());

    ASSERT_NEAR(5.0, tmp.distance(tmp_1), 0.0001);
}

TEST(Squad, constructors) {
    squad::Squad squad = squad::Squad(constant::unit::DENDROID);

    ASSERT_EQ(constant::speed[constant::unit::DENDROID],
              squad.get_speed());

    ASSERT_EQ(constant::max_health[constant::unit::DENDROID],
              squad.get_health());

    ASSERT_EQ(constant::max_quantity[constant::unit::DENDROID],
              squad.get_quantity());
}

TEST(Squad, functions) {
    squad::Squad lord = squad::Squad(constant::unit::LORD);
    squad::Squad lord1 = squad::Squad(constant::unit::LORD);

    ASSERT_TRUE(lord1 == lord);

    lord.get_damage(10);
    ASSERT_EQ(lord.get_health(), lord.get_max_health() - 10);
    ASSERT_TRUE(lord1 != lord);
}

//  Landscape

TEST(Landscape, constructors_getters) {
    game::Landscape game;

    ASSERT_NO_THROW(game.get_map());
    auto &map = game.get_map();
    for (auto &row : map) {
        for (auto &cell : row) {
            std::cout << static_cast<unsigned>(cell.get_type()) << " | ";
        }
        std::cout << std::endl;
    }

    ASSERT_NO_THROW(game.get_units_list());
    auto &list = game.get_units_list();
    std::cout << list.size() << std::endl;
}

TEST(Landscape, other_func) {
    game::Landscape game;
    std::vector<unsigned> args = {0, 1, 0};

    auto &map = game.get_map();
    for (auto &row : map) {
        for (auto &cell : row) {
            std::cout << static_cast<unsigned>(cell.get_type()) << " | ";
        }
        std::cout << std::endl;
    }
    auto &list = game.get_units_list();
    std::cout << list.size() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    auto *lord1 = game.get_next();
    auto name = lord1->get_name();
    std::string lord_name = "L";
    if (constant::unit_type[name] == lord_name) {
        auto lord = static_cast<squad::Lord *>(lord1);
        std::cout << lord->get_lord_name() << std::endl;
    }

    game.play_next('c', args);

    auto &map1 = game.get_map();
    for (auto &row : map1) {
        for (auto &cell : row) {
            std::cout << static_cast<unsigned>(cell.get_type()) << " | ";
        }
        std::cout << std::endl;
    }

    auto &list1 = game.get_units_list();
    std::cout << list1.size() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::vector<unsigned> args1 = {0, 0, 1};

    auto *lord2 = game.get_next();
    auto name2 = lord1->get_name();
    if (constant::unit_type[name2] == lord_name) {
        auto lord = static_cast<squad::Lord *>(lord2);
        std::cout << lord->get_lord_name() << std::endl;
    }
    game.play_next('c', args1);

    auto &map2 = game.get_map();
    for (auto &row : map2) {
        for (auto &cell : row) {
            std::cout << static_cast<unsigned>(cell.get_type()) << " | ";
        }
        std::cout << std::endl;
    }

    auto &list2 = game.get_units_list();
    std::cout << list2.size() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::vector<unsigned> args3 = {5, 18};

    game.play_next('a', args3);

    auto &map3 = game.get_map();
    for (auto &row : map3) {
        for (auto &cell : row) {
            std::cout << static_cast<unsigned>(cell.get_type()) << " | ";
        }
        std::cout << std::endl;
    }

    auto *squad = game.get_next();
    std::cout << squad->get_health() << std::endl;
}

//  Lord

TEST(Lord, constructors_getters) {
    std::string str = "Max";
    squad::Lord lord(str, 0);

    ASSERT_EQ(str, lord.get_lord_name());
    ASSERT_EQ(100, lord.get_energy());
    ASSERT_EQ(1000, lord.get_max_energy());
}

TEST(Lord, other_func) {
    std::string str = "Max";
    squad::Lord lord(str, 1);

    school::School school(constant::school_type::ROBOTICS);
    squad::Moral squad(squad::moral_type::ROBOMECH);
    school::Skill skill = school::Skill(constant::unit::ROBOMECH, 0, 30, 1.0);
    school.add_skill(skill);

    squad::Amoral squad_1(squad::amoral_type::CENTRY);
    school::Skill skill_1(constant::unit::CENTRY, 1, 70, 1.0);
    school.add_skill(skill_1);

    squad::Immortal_amoral squad_2(squad::immortal_amoral_type::COLOSSUS);
    school::Skill skill_2(constant::unit::COLOSSUS, 2, 150, 1.1);
    school.add_skill(skill_2);

    std::map<school::School, unsigned> knowledge = {{school, 0}, {school, 0}, {school, 0}, {school, 0}, {school, 0}};

    ASSERT_NO_THROW(lord.set_knowledge(knowledge));

    squad::Squad *tmp;
    ASSERT_NO_THROW(tmp = lord.call_squad(constant::unit::ROBOMECH));
    auto tmp_1 = static_cast<squad::Moral *>(tmp);

    ASSERT_EQ(constant::unit::ROBOMECH, tmp_1->get_name());
    ASSERT_EQ(constant::max_health[constant::unit::ROBOMECH],
              tmp_1->get_max_health());
    ASSERT_EQ(0, tmp_1->get_moral());
    ASSERT_EQ(squad::moral_type::ROBOMECH, tmp_1->get_type());
    ASSERT_EQ(70, lord.get_energy());
    ASSERT_ANY_THROW(lord.call_squad(constant::unit::CENTRY));
    ASSERT_NO_THROW(lord.upgrade_school(constant::school_type::ROBOTICS));
    ASSERT_EQ(160, lord.get_experience());
}

//  School

TEST(School, constructors_getters) {
    school::School school(constant::school_type::NANOSLIME);

    ASSERT_EQ(constant::school_type::NANOSLIME, school.get_type());
}

TEST(School, setters) {
    school::School school(constant::school_type::NANOSLIME);

    ASSERT_EQ(constant::school_type::NANOSLIME, school.get_type());

    squad::Immortal_amoral squad(squad::immortal_amoral_type::COLOSSUS);
    school::Skill skill(constant::unit::COLOSSUS, 10, 30, 1.1);

    ASSERT_NO_THROW(school.add_skill(skill));
}

//  Skill

TEST(Skill, constructors_getters) {
    squad::Immortal_amoral squad(squad::immortal_amoral_type::COLOSSUS);
    school::Skill skill(constant::unit::COLOSSUS, 10, 30, 1.1);

    ASSERT_EQ(constant::unit::COLOSSUS, skill.get_name());
    ASSERT_EQ(10, skill.get_minimal_study());
    ASSERT_EQ(30, skill.get_energy());
    ASSERT_EQ(1.1, skill.get_count_coefficient());
}

TEST(Skill, setters) {
    squad::Immortal_amoral squad(squad::immortal_amoral_type::COLOSSUS);
    school::Skill skill(constant::unit::COLOSSUS, 10, 30, 1.1);

    ASSERT_EQ(constant::unit::COLOSSUS, skill.get_name());
    ASSERT_EQ(10, skill.get_minimal_study());
    ASSERT_EQ(30, skill.get_energy());
    ASSERT_EQ(1.1, skill.get_count_coefficient());

    skill.set_count_coefficient(1.3);
    skill.set_minimal_study(400);
    skill.set_energy(20);
    skill.set_name(constant::unit::CYCLONE);

    ASSERT_EQ(constant::unit::CYCLONE, skill.get_name());
    ASSERT_EQ(400, skill.get_minimal_study());
    ASSERT_EQ(20, skill.get_energy());
    ASSERT_EQ(1.3, skill.get_count_coefficient());
}

TEST(Skill, other_func) {
    squad::Immortal_amoral squad(squad::immortal_amoral_type::COLOSSUS);
    school::Skill skill(constant::unit::COLOSSUS, 10, 30, 1.1);

    std::vector<constant::unit> chill = {constant::unit::ROBOMECH, constant::unit::DISRUPTOR, constant::unit::CYCLONE};

    skill.set_easy_kill(chill);
    ASSERT_EQ(chill, skill.get_easy_kill());
    skill.add_easy_kill(constant::unit::ELF);
    ASSERT_NE(chill, skill.get_easy_kill());
    skill.remove_easy_kill(constant::unit::ELF);
    ASSERT_EQ(chill, skill.get_easy_kill());
    ASSERT_EQ(true, skill.check_easy_kill(constant::unit::DISRUPTOR));
    ASSERT_EQ(false, skill.check_easy_kill(constant::unit::DENDROID));
}

//  Moral

TEST(Moral, constructors_getters) {
    squad::Moral squad(squad::moral_type::MARINE, 2);

    ASSERT_EQ(squad::moral_type::MARINE, squad.get_type());
    ASSERT_EQ(2, squad.get_moral());
}

TEST(Moral, setters) {
    squad::Moral squad(squad::moral_type::MARINE, 2);

    ASSERT_EQ(squad::moral_type::MARINE, squad.get_type());
    ASSERT_EQ(2, squad.get_moral());

    squad.set_type(squad::moral_type::GHOST);
    squad.set_moral(-2);

    ASSERT_EQ(squad::moral_type::GHOST, squad.get_type());
    ASSERT_EQ(-2, squad.get_moral());
}

TEST(Moral, other_func) {
    squad::Moral squad(squad::moral_type::MARINE, 2);

    ASSERT_EQ(squad::moral_type::MARINE, squad.get_type());
    ASSERT_EQ(2, squad.get_moral());

    squad.balance_moral();

    ASSERT_EQ(1, squad.get_moral());

    squad.modify_moral(3);

    ASSERT_EQ(4, squad.get_moral());

    squad::Amoral squad_1(squad::amoral_type::CYCLONE);

    ASSERT_NO_THROW(squad.attack(squad_1));
    ASSERT_EQ(46, squad_1.get_health());
}

//  Amoral

TEST(Amoral, constructors_getters) {
    squad::Amoral squad(squad::amoral_type::CYCLONE);

    ASSERT_EQ(squad::amoral_type::CYCLONE, squad.get_type());
}

TEST(Amoral, setters) {
    squad::Amoral squad(squad::amoral_type::CYCLONE);

    ASSERT_EQ(squad::amoral_type::CYCLONE, squad.get_type());

    squad.set_type(squad::amoral_type::GNOME);

    ASSERT_EQ(squad::amoral_type::GNOME, squad.get_type());
}

TEST(Amoral, other_func) {
    squad::Amoral squad(squad::amoral_type::CYCLONE);

    ASSERT_EQ(squad::amoral_type::CYCLONE, squad.get_type());

    squad::Moral squad_1(squad::moral_type::MARINE, 2);

    ASSERT_NO_THROW(squad.attack(squad_1));
}

//  Immortal_moral

TEST(Immortal_moral, constructors_getters) {
    squad::Immortal_moral tmp(squad::immortal_moral_type::DENDROID);
    ASSERT_EQ(squad::immortal_moral_type::DENDROID, tmp.get_type());
    squad::Immortal_moral tmp_1(squad::immortal_moral_type::MIMIC);
    ASSERT_EQ(squad::immortal_moral_type::MIMIC, tmp_1.get_type());
}

TEST(Immortal_moral, setters) {
    squad::Immortal_moral tmp(squad::immortal_moral_type::REAPER);
    ASSERT_EQ(squad::immortal_moral_type::REAPER, tmp.get_type());
    tmp.set_type(squad::immortal_moral_type::MIMIC);
    ASSERT_EQ(squad::immortal_moral_type::MIMIC, tmp.get_type());
}

TEST(Immortal_moral, other_func) {
    squad::Immortal_moral tmp(squad::immortal_moral_type::REAPER);
    ASSERT_EQ(squad::immortal_moral_type::REAPER, tmp.get_type());
    tmp.set_probability(1.0);
    ASSERT_EQ(constant::max_health[constant::REAPER], tmp.get_health());
    tmp.set_health(constant::max_health[constant::REAPER] / 2);
    tmp.set_restore(constant::max_health[constant::REAPER]);
    tmp.heal();
    ASSERT_EQ(constant::max_health[constant::REAPER], tmp.get_health());
}

// Immortal_amoral

TEST(Immortal_amoral, constructors_getters) {
    squad::Immortal_amoral tmp(squad::immortal_amoral_type::COLOSSUS);
    ASSERT_EQ(squad::immortal_amoral_type::COLOSSUS, tmp.get_type());
    squad::Immortal_amoral tmp_1(squad::immortal_amoral_type::DISRUPTOR);
    ASSERT_EQ(squad::immortal_amoral_type::DISRUPTOR, tmp_1.get_type());
}

TEST(Immortal_amoral, setters) {
    squad::Immortal_amoral tmp(squad::immortal_amoral_type::COLOSSUS);
    ASSERT_EQ(squad::immortal_amoral_type::COLOSSUS, tmp.get_type());
    tmp.set_type(squad::immortal_amoral_type::DISRUPTOR);
    ASSERT_EQ(squad::immortal_amoral_type::DISRUPTOR, tmp.get_type());
}

TEST(Immortal_amoral, other_func) {
    squad::Immortal_amoral tmp(squad::immortal_amoral_type::COLOSSUS);
    ASSERT_EQ(squad::immortal_amoral_type::COLOSSUS, tmp.get_type());
    tmp.set_probability(1.0);
    ASSERT_EQ(constant::max_health[constant::COLOSSUS], tmp.get_health());
    tmp.set_health(constant::max_health[constant::COLOSSUS] / 2);
    tmp.set_restore(constant::max_health[constant::COLOSSUS]);
    tmp.heal();
    ASSERT_EQ(constant::max_health[constant::COLOSSUS], tmp.get_health());

    squad::Moral squad(squad::moral_type::MARINE, 2);

    ASSERT_NO_THROW(squad.attack(tmp));
    ASSERT_EQ(198, tmp.get_health());
}

//  KDTree

typedef size_t node;

struct point_3D {
    double x, y, z;
    const static int dimension = 2;

    double getDimension(int dim) const {
        switch (dim) {
            case 0:
                return x;
            case 1:
                return y;
            default:
                return std::numeric_limits<double>::quiet_NaN();
        }
    }

    bool operator==(const point_3D &point) const {
        if (this->x == point.x && this->y == point.y)
            return true;
        return false;
    }
};

std::ostream &operator<<(std::ostream &cout, const point_3D &point) {
    cout << '(' << point.x << ", " << point.y << ')';
    return cout;
}

TEST(KDTree, all_tests) {
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

    for (auto n : closeNodes) {
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

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}