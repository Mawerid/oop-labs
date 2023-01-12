#include <gtest/gtest.h>
#include <math.h>

#include "../include/landscape.hpp"
// #include "../include/kdtree.hpp"

TEST(Cell, constructors_getters) {
    field::point tmp;
    ASSERT_EQ(0, tmp.get_x());
    ASSERT_EQ(0, tmp.get_y());

    field::point tmp_1(2, 3);
    ASSERT_EQ(2, tmp_1.get_x());
    ASSERT_EQ(3, tmp_1.get_y());

    field::Cell cell(tmp, field::cell_type::FREE, nullptr);

    ASSERT_EQ(tmp, cell.get_coor());
    ASSERT_EQ(field::cell_type::FREE, cell.get_type());
    ASSERT_EQ(nullptr, cell.get_filling());
}

TEST(Cell, setters) {
    field::point tmp;
    ASSERT_EQ(0, tmp.get_x());
    ASSERT_EQ(0, tmp.get_y());

    field::Cell cell(tmp, field::cell_type::FREE, nullptr);

    ASSERT_EQ(tmp, cell.get_coor());
    ASSERT_EQ(field::cell_type::FREE, cell.get_type());
    ASSERT_EQ(nullptr, cell.get_filling());

    field::point tmp_1(2, 3);
    ASSERT_EQ(2, tmp_1.get_x());
    ASSERT_EQ(3, tmp_1.get_y());

    cell.set_coor(tmp_1);
    cell.set_type(field::cell_type::BUSY);

    ASSERT_EQ(tmp_1, cell.get_coor());
    ASSERT_EQ(field::cell_type::BUSY, cell.get_type());
}

TEST(Cell, other_func) {
    field::point tmp;
    ASSERT_EQ(0, tmp.get_x());
    ASSERT_EQ(0, tmp.get_y());

    field::point tmp_1(3, 4);
    ASSERT_EQ(3, tmp_1.get_x());
    ASSERT_EQ(4, tmp_1.get_y());

    ASSERT_NEAR(5.0, tmp.distance(tmp_1), 0.0001);
}

TEST(Squad, constructors) {
    squad::Squad squad = squad::Squad(constant::unit::DENDRIOD);

    ASSERT_EQ(constant::speed[constant::unit::DENDRIOD],
              squad.get_speed());

    ASSERT_EQ(constant::max_health[constant::unit::DENDRIOD],
              squad.get_health());

    ASSERT_EQ(constant::max_quantity[constant::unit::DENDRIOD],
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

// TEST(Landscape, constructors_getters)
// {
//     squad::Immortal_amoral squad;
//     school::Skill skill(constant::unit::COLOSSUS, squad, 10, 30, 1.1);

//     ASSERT_EQ(constant::unit::COLOSSUS, skill.get_name());
//     ASSERT_EQ(10, skill.get_min_study());
//     ASSERT_EQ(30, skill.get_energy());
//     ASSERT_NEAR(1.1, skill.get_count_coef(), 0.0001);

//     skill.set_count_coef(1.3);
//     skill.set_min_study(400);
//     skill.set_energy(20);
//     skill.set_name(constant::unit::CYCLONE);

//     ASSERT_EQ(constant::unit::CYCLONE, skill.get_name());
//     ASSERT_EQ(400, skill.get_min_study());
//     ASSERT_EQ(20, skill.get_energy());
//     ASSERT_EQ(1.3, skill.get_count_coef());
// }

// TEST(Landscape, setters)
// {
//     squad::Immortal_amoral squad;
//     school::Skill skill(constant::unit::COLOSSUS, squad, 10, 30, 1.1);

//     ASSERT_EQ(constant::unit::COLOSSUS, skill.get_name());
//     ASSERT_EQ(10, skill.get_min_study());
//     ASSERT_EQ(30, skill.get_energy());
//     ASSERT_EQ(1.1, skill.get_count_coef());

//     skill.set_count_coef(1.3);
//     skill.set_min_study(400);
//     skill.set_energy(20);
//     skill.set_name(constant::unit::CYCLONE);

//     ASSERT_EQ(constant::unit::CYCLONE, skill.get_name());
//     ASSERT_EQ(400, skill.get_min_study());
//     ASSERT_EQ(20, skill.get_energy());
//     ASSERT_EQ(1.3, skill.get_count_coef());
// }

// TEST(Landscape, other_func)
// {
//     squad::Immortal_amoral squad;
//     school::Skill skill(constant::unit::COLOSSUS, squad, 10, 30, 1.1);

//     ASSERT_EQ(constant::unit::COLOSSUS, skill.get_name());
//     ASSERT_EQ(10, skill.get_min_study());
//     ASSERT_EQ(30, skill.get_energy());
//     ASSERT_EQ(1.1, skill.get_count_coef());

//     skill.set_count_coef(1.3);
//     skill.set_min_study(400);
//     skill.set_energy(20);
//     skill.set_name(constant::unit::CYCLONE);

//     ASSERT_EQ(constant::unit::CYCLONE, skill.get_name());
//     ASSERT_EQ(400, skill.get_min_study());
//     ASSERT_EQ(20, skill.get_energy());
//     ASSERT_EQ(1.3, skill.get_count_coef());
// }

// //  Lord

// TEST(Lord, constructors_getters)
// {
//     std::string str = "Max";
//     squad::Lord lord(str, 100, 300);

//     ASSERT_EQ(str, lord.get_name());
//     ASSERT_EQ(100, lord.get_energy());
//     ASSERT_EQ(300, lord.get_max_energy());
// }

// TEST(Lord, other_func)
// {
//     std::string str = "Max";
//     squad::Lord lord(str, 100, 300);

//     school::School school(constant::school_type::ROBOTICS);
//     squad::Moral squad(squad::moral_type::ROBOMECH);
//     squad.set_max_health(constant::max_health::ROBOMECH_MH);
//     squad.set_damage_val(constant::damage::ROBOMECH_DM);
//     squad.set_defense_val(constant::defense::ROBOMECH_DF);
//     squad.set_health(constant::max_health::ROBOMECH_MH);
//     squad.set_motivation(constant::motivation::ROBOMECH_MT);
//     squad.set_quantity(constant::max_quantity::ROBOMECH_MQ);
//     squad.set_team(game::player_type::RIGHT);
//     squad.set_experience(constant::experience::ROBOMECH_EX);
//     squad.set_name(constant::unit::ROBOMECH);
//     squad.set_speed(constant::speed::ROBOMECH_S);

//     school::Skill skill(constant::unit::ROBOMECH, squad, 0, 30, 1.0);

//     school.add_skill(skill);

//     squad::Amoral squad_1(squad::amoral_type::CENTRY);
//     squad_1.set_max_health(constant::max_health::CENTRY_MH);
//     squad_1.set_damage_val(constant::damage::CENTRY_DM);
//     squad_1.set_defense_val(constant::defense::CENTRY_DF);
//     squad_1.set_health(constant::max_health::CENTRY_MH);
//     squad_1.set_motivation(constant::motivation::CENTRY_MT);
//     squad_1.set_quantity(constant::max_quantity::CENTRY_MQ);
//     squad_1.set_team(game::player_type::RIGHT);
//     squad_1.set_experience(constant::experience::CENTRY_EX);
//     squad_1.set_name(constant::unit::CENTRY);
//     squad_1.set_speed(constant::speed::CENTRY_S);

//     school::Skill skill_1(constant::unit::CENTRY, squad_1, 1, 70, 1.0);

//     school.add_skill(skill_1);

//     squad::Immortal_amoral squad_2(squad::immortal_amoral_type::COLOSSUS);
//     squad_2.set_max_health(constant::max_health::COLOSSUS_MH);
//     squad_2.set_damage_val(constant::damage::COLOSSUS_DM);
//     squad_2.set_defense_val(constant::defense::COLOSSUS_DF);
//     squad_2.set_health(constant::max_health::COLOSSUS_MH);
//     squad_2.set_motivation(constant::motivation::COLOSSUS_MT);
//     squad_2.set_quantity(constant::max_quantity::COLOSSUS_MQ);
//     squad_2.set_team(game::player_type::RIGHT);
//     squad_2.set_experience(constant::experience::COLOSSUS_EX);
//     squad_2.set_name(constant::unit::COLOSSUS);
//     squad_2.set_speed(constant::speed::COLOSSUS_S);

//     school::Skill skill_2(constant::unit::COLOSSUS, squad_2, 2, 150, 1.1);

//     school.add_skill(skill_2);

//     std::map<school::School, unsigned> knowledge = {{school, 0}, {school, 0}, {school, 0}, {school, 0}, {school, 0}};

//     ASSERT_NO_THROW(lord.set_knowledge(knowledge));

//     squad::Squad *tmp;

//     ASSERT_NO_THROW(tmp = lord.call_squad(constant::unit::ROBOMECH));

//     auto tmp_1 = static_cast<squad::Moral *>(tmp);

//     ASSERT_EQ(constant::unit::ROBOMECH, tmp_1->get_name());
//     ASSERT_EQ(constant::max_health::ROBOMECH_MH, tmp_1->get_max_health());
//     ASSERT_EQ(0, tmp_1->get_moral_val());
//     ASSERT_EQ(squad::moral_type::ROBOMECH, tmp_1->get_type());

//     ASSERT_EQ(70, lord.get_energy());
//     ASSERT_EQ(nullptr, lord.call_squad(constant::unit::CENTRY));

//     ASSERT_NO_THROW(lord.upgrade_school(constant::school_type::ROBOTICS));

//     ASSERT_EQ(40, lord.get_energy());
// }

// //  School

// TEST(School, constructors_getters)
// {
//     school::School school(constant::school_type::NANOSLIME);

//     ASSERT_EQ(constant::school_type::NANOSLIME, school.get_type());
// }

// TEST(School, setters)
// {
//     school::School school(constant::school_type::NANOSLIME);

//     ASSERT_EQ(constant::school_type::NANOSLIME, school.get_type());

//     squad::Immortal_amoral squad;
//     school::Skill skill(constant::unit::COLOSSUS, squad, 10, 30, 1.1);

//     ASSERT_NO_THROW(school.add_skill(skill));
// }

// //  Skill

// TEST(Skill, constructors_getters)
// {
//     squad::Immortal_amoral squad;
//     school::Skill skill(constant::unit::COLOSSUS, squad, 10, 30, 1.1);

//     ASSERT_EQ(constant::unit::COLOSSUS, skill.get_name());
//     ASSERT_EQ(10, skill.get_min_study());
//     ASSERT_EQ(30, skill.get_energy());
//     ASSERT_EQ(1.1, skill.get_count_coef());
// }

// TEST(Skill, setters)
// {
//     squad::Immortal_amoral squad;
//     school::Skill skill(constant::unit::COLOSSUS, squad, 10, 30, 1.1);

//     ASSERT_EQ(constant::unit::COLOSSUS, skill.get_name());
//     ASSERT_EQ(10, skill.get_min_study());
//     ASSERT_EQ(30, skill.get_energy());
//     ASSERT_EQ(1.1, skill.get_count_coef());

//     skill.set_count_coef(1.3);
//     skill.set_min_study(400);
//     skill.set_energy(20);
//     skill.set_name(constant::unit::CYCLONE);

//     ASSERT_EQ(constant::unit::CYCLONE, skill.get_name());
//     ASSERT_EQ(400, skill.get_min_study());
//     ASSERT_EQ(20, skill.get_energy());
//     ASSERT_EQ(1.3, skill.get_count_coef());
// }

// TEST(Skill, other_func)
// {
//     squad::Immortal_amoral squad;
//     school::Skill skill(constant::unit::COLOSSUS, squad, 10, 30, 1.1);

//     std::vector<constant::unit> chill = {constant::unit::ROBOMECH, constant::unit::DISRUPTOR, constant::unit::CYCLONE};

//     skill.set_easy_kill(chill);
//     ASSERT_EQ(chill, skill.get_easy_kill());
//     skill.add_easy_kill(constant::unit::ELF);
//     ASSERT_NE(chill, skill.get_easy_kill());
//     skill.remove_easy_kill(constant::unit::ELF);
//     ASSERT_EQ(chill, skill.get_easy_kill());
//     ASSERT_EQ(true, skill.check_easy_kill(constant::unit::DISRUPTOR));
//     ASSERT_EQ(false, skill.check_easy_kill(constant::unit::DENDRIOD));
// }

// //  Moral

// TEST(Moral, constructors_getters)
// {
//     squad::Moral squad(squad::moral_type::MARINE, 2);

//     ASSERT_EQ(squad::moral_type::MARINE, squad.get_type());
//     ASSERT_EQ(2, squad.get_moral_val());
// }

// TEST(Moral, setters)
// {
//     squad::Moral squad(squad::moral_type::MARINE, 2);

//     ASSERT_EQ(squad::moral_type::MARINE, squad.get_type());
//     ASSERT_EQ(2, squad.get_moral_val());

//     squad.set_type(squad::moral_type::GHOST);
//     squad.set_moral_val(-2);

//     ASSERT_EQ(squad::moral_type::GHOST, squad.get_type());
//     ASSERT_EQ(-2, squad.get_moral_val());
// }

// TEST(Moral, other_func)
// {
//     squad::Moral squad(squad::moral_type::MARINE, 2);

//     squad.set_max_health(constant::max_health::MARINE_MH);
//     squad.set_damage_val(constant::damage::MARINE_DM);
//     squad.set_defense_val(constant::defense::MARINE_DF);
//     squad.set_health(constant::max_health::MARINE_MH);
//     squad.set_motivation(constant::motivation::MARINE_MT);
//     squad.set_quantity(constant::max_quantity::MARINE_MQ);
//     squad.set_team(game::player_type::LEFT);
//     squad.set_experience(constant::experience::MARINE_EX);
//     squad.set_name(constant::unit::MARINE);
//     squad.set_speed(constant::speed::MARINE_S);

//     ASSERT_EQ(squad::moral_type::MARINE, squad.get_type());
//     ASSERT_EQ(2, squad.get_moral_val());

//     squad.balance();

//     ASSERT_EQ(1, squad.get_moral_val());

//     squad.mod_moral(3);

//     ASSERT_EQ(4, squad.get_moral_val());

//     squad::Amoral squad_1(squad::amoral_type::CYCLONE);

//     squad_1.set_max_health(constant::max_health::CYCLONE_MH);
//     squad_1.set_damage_val(constant::damage::CYCLONE_DM);
//     squad_1.set_defense_val(constant::defense::CYCLONE_DF);
//     squad_1.set_health(constant::max_health::CYCLONE_MH);
//     squad_1.set_motivation(constant::motivation::CYCLONE_MT);
//     squad_1.set_quantity(constant::max_quantity::CYCLONE_MQ);
//     squad_1.set_team(game::player_type::RIGHT);
//     squad_1.set_experience(constant::experience::CYCLONE_EX);
//     squad_1.set_name(constant::unit::CYCLONE);
//     squad_1.set_speed(constant::speed::CYCLONE_S);

//     ASSERT_NO_THROW(squad.hit(&squad_1));
//     ASSERT_EQ(275, squad_1.get_health());
//     ASSERT_NO_THROW(squad.defence(&squad_1));
//     ASSERT_EQ(249, squad.get_health());
// }

// //  Amoral

// TEST(Amoral, constructors_getters)
// {
//     squad::Amoral squad(squad::amoral_type::CYCLONE);

//     ASSERT_EQ(squad::amoral_type::CYCLONE, squad.get_type());
// }

// TEST(Amoral, setters)
// {
//     squad::Amoral squad(squad::amoral_type::CYCLONE);

//     ASSERT_EQ(squad::amoral_type::CYCLONE, squad.get_type());

//     squad.set_type(squad::amoral_type::GNOME);

//     ASSERT_EQ(squad::amoral_type::GNOME, squad.get_type());
// }

// TEST(Amoral, other_func)
// {
//     squad::Amoral squad(squad::amoral_type::CYCLONE);

//     ASSERT_EQ(squad::amoral_type::CYCLONE, squad.get_type());

//     squad::Moral squad_1(squad::moral_type::MARINE, 2);

//     ASSERT_NO_THROW(squad.hit(&squad_1));
//     ASSERT_NO_THROW(squad.defence(&squad_1));
// }

// //  Immortal_moral

// TEST(Immortal_moral, constructors_getters)
// {
//     squad::Immortal_moral tmp;
//     ASSERT_EQ(squad::immortal_moral_type::REAPER, tmp.get_type());
//     squad::Immortal_moral tmp_1(squad::immortal_moral_type::MIMIC);
//     ASSERT_EQ(squad::immortal_moral_type::MIMIC, tmp_1.get_type());
// }

// TEST(Immortal_moral, setters)
// {
//     squad::Immortal_moral tmp;
//     ASSERT_EQ(squad::immortal_moral_type::REAPER, tmp.get_type());
//     tmp.set_type(squad::immortal_moral_type::MIMIC);
//     ASSERT_EQ(squad::immortal_moral_type::MIMIC, tmp.get_type());
// }

// TEST(Immortal_moral, other_func)
// {
//     squad::Immortal_moral tmp;
//     ASSERT_EQ(squad::immortal_moral_type::REAPER, tmp.get_type());
//     tmp.set_probability(1.0);
//     tmp.set_max_health(constant::max_health::REAPER_MH);
//     tmp.set_health(constant::max_health::REAPER_MH);
//     ASSERT_EQ(constant::max_health::REAPER_MH, tmp.get_health());
//     tmp.set_health(constant::max_health::REAPER_MH / 2);
//     tmp.set_restore(constant::max_health::REAPER_MH);
//     tmp.heal();
//     ASSERT_EQ(constant::max_health::REAPER_MH, tmp.get_health());
// }

// // Immortal_amoral

// TEST(Immortal_amoral, constructors_getters)
// {
//     squad::Immortal_amoral tmp;
//     ASSERT_EQ(squad::immortal_amoral_type::COLOSSUS, tmp.get_type());
//     squad::Immortal_amoral tmp_1(squad::immortal_amoral_type::DISRUPTOR);
//     ASSERT_EQ(squad::immortal_amoral_type::DISRUPTOR, tmp_1.get_type());
// }

// TEST(Immortal_amoral, setters)
// {
//     squad::Immortal_amoral tmp;
//     ASSERT_EQ(squad::immortal_amoral_type::COLOSSUS, tmp.get_type());
//     tmp.set_type(squad::immortal_amoral_type::DISRUPTOR);
//     ASSERT_EQ(squad::immortal_amoral_type::DISRUPTOR, tmp.get_type());
// }

// TEST(Immortal_amoral, other_func)
// {
//     squad::Immortal_amoral tmp;
//     ASSERT_EQ(squad::immortal_amoral_type::COLOSSUS, tmp.get_type());
//     tmp.set_probability(1.0);
//     tmp.set_max_health(constant::max_health::COLOSSUS_MH);
//     tmp.set_health(constant::max_health::COLOSSUS_MH);
//     ASSERT_EQ(constant::max_health::COLOSSUS_MH, tmp.get_health());
//     tmp.set_health(constant::max_health::COLOSSUS_MH / 2);
//     tmp.set_restore(constant::max_health::COLOSSUS_MH);
//     tmp.heal();
//     ASSERT_EQ(constant::max_health::COLOSSUS_MH, tmp.get_health());

//     tmp.set_max_health(constant::max_health::COLOSSUS_MH);
//     tmp.set_damage_val(constant::damage::COLOSSUS_DM);
//     tmp.set_defense_val(constant::defense::COLOSSUS_DF);
//     tmp.set_health(constant::max_health::COLOSSUS_MH);
//     tmp.set_motivation(constant::motivation::COLOSSUS_MT);
//     tmp.set_quantity(constant::max_quantity::COLOSSUS_MQ);
//     tmp.set_team(game::player_type::RIGHT);
//     tmp.set_experience(constant::experience::COLOSSUS_EX);
//     tmp.set_name(constant::unit::COLOSSUS);
//     tmp.set_speed(constant::speed::COLOSSUS_S);

//     squad::Moral squad(squad::moral_type::MARINE, 2);

//     squad.set_max_health(constant::max_health::MARINE_MH);
//     squad.set_damage_val(constant::damage::MARINE_DM);
//     squad.set_defense_val(constant::defense::MARINE_DF);
//     squad.set_health(constant::max_health::MARINE_MH);
//     squad.set_motivation(constant::motivation::MARINE_MT);
//     squad.set_quantity(constant::max_quantity::MARINE_MQ);
//     squad.set_team(game::player_type::LEFT);
//     squad.set_experience(constant::experience::MARINE_EX);
//     squad.set_name(constant::unit::MARINE);
//     squad.set_speed(constant::speed::MARINE_S);

//     ASSERT_NO_THROW(squad.hit(&tmp));
//     ASSERT_EQ(425, tmp.get_health());
//     ASSERT_NO_THROW(squad.defence(&tmp));
//     ASSERT_EQ(249, squad.get_health());
// }

// //  KDTree

// typedef size_t node;

// struct point_3D
// {
//     double x, y, z;
//     const static int dimension = 2;

//     double getDimension(int dim) const
//     {
//         switch (dim)
//         {
//         case 0:
//             return x;
//         case 1:
//             return y;
//         default:
//             return std::numeric_limits<double>::quiet_NaN();
//         }
//     }

//     bool operator==(const point_3D &point) const
//     {
//         if (this->x == point.x && this->y == point.y)
//             return true;
//         return false;
//     }
// };

// std::ostream &operator<<(std::ostream &cout, const point_3D &point)
// {
//     cout << '(' << point.x << ", " << point.y << ')';
//     return cout;
// }

// TEST(KDTree, all_tests)
// {
//     std::KDTree<point_3D> tree;

//     std::vector<point_3D> pts{{0, 0}, {1, 1}, {-1, 3}, {5, 6}, {2, -6}, {4, 5}, {2, 3}, {2, 5}};
//     tree.buildTree(pts);
//     tree.dumpTreeInorder(std::cout);

//     point_3D point_0{0, 0};

//     ASSERT_EQ(point_0, tree.getPoint(0));

//     std::vector<node> check = {1, 0};

//     auto closeNodes = tree.getPointsWithinCube({0, 0, 0}, 1);

//     ASSERT_EQ(check, closeNodes);

//     std::ostringstream stream;

//     char str[] = "(1, 1)\n(0, 0)\n";

//     for (auto n : closeNodes)
//     {
//         tree.dumpNode(n, stream);
//     }

//     ASSERT_STREQ(str, stream.str().c_str());

//     ASSERT_EQ(2, tree.findMin(0));
//     ASSERT_EQ(4, tree.findMin(1));
//     ASSERT_EQ(4, tree.findMin(2));

//     ASSERT_NO_THROW(tree.deletePoint(2));
//     ASSERT_NO_THROW(tree.dumpTreeInorder(std::cout));
// }

// main

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}