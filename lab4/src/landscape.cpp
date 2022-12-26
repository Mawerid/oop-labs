#include "../include/landscape.hpp"
#include <stdexcept>
#include <iostream>

namespace game
{
    Landscape::Landscape()
    {
        school_table = {};
        map = {};
        units_list = {};
    }

    Landscape::Landscape(const map_type &root)
    {
        school_table = {};
        map = root;
        units_list = {};
    }

    void Landscape::set_school_table(const school_table_type &new_table) { school_table = new_table; }

    void Landscape::set_map(const map_type &root) { map = root; }

    void Landscape::set_units_list(const list &new_list) { units_list = new_list; }

    Landscape::school_table_type Landscape::get_school_table() const { return school_table; }

    Landscape::map_type Landscape::get_map() const { return map; }

    Landscape::list Landscape::get_units_list() const { return units_list; }

    void Landscape::move_squad(field::Cell *cell_1, field::Cell *cell_2)
    {
        auto *tmp = cell_1->get_filling();
        cell_1->set_filling(cell_2->get_filling());
        cell_2->set_filling(tmp);
    }

    void Landscape::set_squad(field::Cell *cell, squad::Squad *squad)
    {
        if (cell->get_type() != field::cell_type::FREE)
            throw std::invalid_argument("There is already a squad");
        cell->set_filling(squad);
    }

    void Landscape::play_next()
    {
        squad::Squad *squad = units_list.front();
        units_list.pop_front();

        auto unit = squad->get_name();
        if (unit % 3 == 1 || unit == 2 || unit == 5)
            squad = static_cast<squad::Amoral *>(squad);
        else if (unit % 3 == 0 || unit == 14 || unit == 11)
            squad = static_cast<squad::Moral *>(squad);
        else if (unit == 14 || unit == 11)
            squad = static_cast<squad::Immortal_moral *>(squad);
        else if (unit == 2 || unit == 5)
            squad = static_cast<squad::Immortal_amoral *>(squad);
        else
            squad = static_cast<squad::Lord *>(squad);

        char what_to_do;
        std::cin >> what_to_do;

        switch (what_to_do)
        {
        case 'h':
            std::cout << "Enter position of your enemy:" << std::endl;

            break;
        case 'm':
            // move_squad()
            break;
        case 'u':
            // squad.upgrade_school();
            break;
        case 'c':
            // squad.call_squad();
        default:
            break;
        }

        if (squad)
            units_list.push_back(squad);
    }

    void Landscape::init()
    {
        // INIT SKILLS

        squad::Moral unit_1(squad::moral_type::ROBOMECH, 0);
        unit_1.set_max_health(constant::max_health::ROBOMECH_MH);
        unit_1.set_damage_val(constant::damage::ROBOMECH_DM);
        unit_1.set_defense_val(constant::defense::ROBOMECH_DF);
        unit_1.set_motivation(constant::motivation::ROBOMECH_MT);
        unit_1.set_quantity(constant::max_quantity::ROBOMECH_MQ);
        unit_1.set_experience(constant::experience::ROBOMECH_EX);
        unit_1.set_name(constant::unit::ROBOMECH);
        unit_1.set_speed(constant::speed::ROBOMECH_S);
        static school::Skill robo(constant::unit::ROBOMECH, (static_cast<squad::Squad>(unit_1)), 0, 30, 1.0);

        squad::Amoral unit_2(squad::amoral_type::CENTRY);
        unit_2.set_max_health(constant::max_health::CENTRY_MH);
        unit_2.set_damage_val(constant::damage::CENTRY_DM);
        unit_2.set_defense_val(constant::defense::CENTRY_DF);
        unit_2.set_motivation(constant::motivation::CENTRY_MT);
        unit_2.set_quantity(constant::max_quantity::CENTRY_MQ);
        unit_2.set_experience(constant::experience::CENTRY_EX);
        unit_2.set_name(constant::unit::CENTRY);
        unit_2.set_speed(constant::speed::CENTRY_S);
        static school::Skill centry(constant::unit::CENTRY, (static_cast<squad::Squad>(unit_2)), 1, 70, 1.0);

        squad::Immortal_amoral unit_3(squad::immortal_amoral_type::COLOSSUS);
        unit_3.set_max_health(constant::max_health::COLOSSUS_MH);
        unit_3.set_damage_val(constant::damage::COLOSSUS_DM);
        unit_3.set_defense_val(constant::defense::COLOSSUS_DF);
        unit_3.set_motivation(constant::motivation::COLOSSUS_MT);
        unit_3.set_quantity(constant::max_quantity::COLOSSUS_MQ);
        unit_3.set_experience(constant::experience::COLOSSUS_EX);
        unit_3.set_name(constant::unit::COLOSSUS);
        unit_3.set_speed(constant::speed::COLOSSUS_S);
        static school::Skill colos(constant::unit::COLOSSUS, (static_cast<squad::Squad>(unit_3)), 2, 100, 1.0);

        squad::Moral unit_4(squad::moral_type::GHOST, 0);
        unit_4.set_max_health(constant::max_health::GHOST_MH);
        unit_4.set_damage_val(constant::damage::GHOST_DM);
        unit_4.set_defense_val(constant::defense::GHOST_DF);
        unit_4.set_motivation(constant::motivation::GHOST_MT);
        unit_4.set_quantity(constant::max_quantity::GHOST_MQ);
        unit_4.set_experience(constant::experience::GHOST_EX);
        unit_4.set_name(constant::unit::GHOST);
        unit_4.set_speed(constant::speed::GHOST_S);
        static school::Skill ghost(constant::unit::GHOST, (static_cast<squad::Squad>(unit_4)), 0, 30, 1.0);

        squad::Amoral unit_5(squad::amoral_type::INFESTOR);
        unit_5.set_max_health(constant::max_health::INFESTOR_MH);
        unit_5.set_damage_val(constant::damage::INFESTOR_DM);
        unit_5.set_defense_val(constant::defense::INFESTOR_DF);
        unit_5.set_motivation(constant::motivation::INFESTOR_MT);
        unit_5.set_quantity(constant::max_quantity::INFESTOR_MQ);
        unit_5.set_experience(constant::experience::INFESTOR_EX);
        unit_5.set_name(constant::unit::INFESTOR);
        unit_5.set_speed(constant::speed::INFESTOR_S);
        static school::Skill infest(constant::unit::INFESTOR, (static_cast<squad::Squad>(unit_5)), 1, 70, 1.0);

        squad::Immortal_amoral unit_6(squad::immortal_amoral_type::DISRUPTOR);
        unit_6.set_max_health(constant::max_health::DISRUPTOR_MH);
        unit_6.set_damage_val(constant::damage::DISRUPTOR_DM);
        unit_6.set_defense_val(constant::defense::DISRUPTOR_DF);
        unit_6.set_motivation(constant::motivation::DISRUPTOR_MT);
        unit_6.set_quantity(constant::max_quantity::DISRUPTOR_MQ);
        unit_6.set_experience(constant::experience::DISRUPTOR_EX);
        unit_6.set_name(constant::unit::DISRUPTOR);
        unit_6.set_speed(constant::speed::DISRUPTOR_S);
        static school::Skill disrup(constant::unit::DISRUPTOR, (static_cast<squad::Squad>(unit_6)), 2, 100, 1.0);

        squad::Moral unit_7(squad::moral_type::ELF, 0);
        unit_7.set_max_health(constant::max_health::ELF_MH);
        unit_7.set_damage_val(constant::damage::ELF_DM);
        unit_7.set_defense_val(constant::defense::ELF_DF);
        unit_7.set_motivation(constant::motivation::ELF_MT);
        unit_7.set_quantity(constant::max_quantity::ELF_MQ);
        unit_7.set_experience(constant::experience::ELF_EX);
        unit_7.set_name(constant::unit::ELF);
        unit_7.set_speed(constant::speed::ELF_S);
        static school::Skill elf(constant::unit::ELF, (static_cast<squad::Squad>(unit_7)), 0, 30, 1.0);

        squad::Amoral unit_8(squad::amoral_type::GNOME);
        unit_8.set_max_health(constant::max_health::GNOME_MH);
        unit_8.set_damage_val(constant::damage::GNOME_DM);
        unit_8.set_defense_val(constant::defense::GNOME_DF);
        unit_8.set_motivation(constant::motivation::GNOME_MT);
        unit_8.set_quantity(constant::max_quantity::GNOME_MQ);
        unit_8.set_experience(constant::experience::GNOME_EX);
        unit_8.set_name(constant::unit::GNOME);
        unit_8.set_speed(constant::speed::GNOME_S);
        static school::Skill gnome(constant::unit::GNOME, (static_cast<squad::Squad>(unit_8)), 1, 70, 1.0);

        squad::Immortal_moral unit_9(squad::immortal_moral_type::DENDRIOD);
        unit_9.set_max_health(constant::max_health::DENDRIOD_MH);
        unit_9.set_damage_val(constant::damage::DENDRIOD_DM);
        unit_9.set_defense_val(constant::defense::DENDRIOD_DF);
        unit_9.set_motivation(constant::motivation::DENDRIOD_MT);
        unit_9.set_quantity(constant::max_quantity::DENDRIOD_MQ);
        unit_9.set_experience(constant::experience::DENDRIOD_EX);
        unit_9.set_name(constant::unit::DENDRIOD);
        unit_9.set_speed(constant::speed::DENDRIOD_S);
        static school::Skill dend(constant::unit::DENDRIOD, (static_cast<squad::Squad>(unit_9)), 2, 100, 1.0);

        squad::Moral unit_10(squad::moral_type::MARINE, 0);
        unit_10.set_max_health(constant::max_health::MARINE_MH);
        unit_10.set_damage_val(constant::damage::MARINE_DM);
        unit_10.set_defense_val(constant::defense::MARINE_DF);
        unit_10.set_motivation(constant::motivation::MARINE_MT);
        unit_10.set_quantity(constant::max_quantity::MARINE_MQ);
        unit_10.set_experience(constant::experience::MARINE_EX);
        unit_10.set_name(constant::unit::MARINE);
        unit_10.set_speed(constant::speed::MARINE_S);
        static school::Skill marine(constant::unit::MARINE, (static_cast<squad::Squad>(unit_10)), 0, 30, 1.0);

        squad::Amoral unit_11(squad::amoral_type::CYCLONE);
        unit_11.set_max_health(constant::max_health::CYCLONE_MH);
        unit_11.set_damage_val(constant::damage::CYCLONE_DM);
        unit_11.set_defense_val(constant::defense::CYCLONE_DF);
        unit_11.set_motivation(constant::motivation::CYCLONE_MT);
        unit_11.set_quantity(constant::max_quantity::CYCLONE_MQ);
        unit_11.set_experience(constant::experience::CYCLONE_EX);
        unit_11.set_name(constant::unit::CYCLONE);
        unit_11.set_speed(constant::speed::CYCLONE_S);
        static school::Skill cycl(constant::unit::CYCLONE, (static_cast<squad::Squad>(unit_11)), 1, 70, 1.0);

        squad::Immortal_moral unit_12(squad::immortal_moral_type::REAPER);
        unit_12.set_max_health(constant::max_health::REAPER_MH);
        unit_12.set_damage_val(constant::damage::REAPER_DM);
        unit_12.set_defense_val(constant::defense::REAPER_DF);
        unit_12.set_motivation(constant::motivation::REAPER_MT);
        unit_12.set_quantity(constant::max_quantity::REAPER_MQ);
        unit_12.set_experience(constant::experience::REAPER_EX);
        unit_12.set_name(constant::unit::REAPER);
        unit_12.set_speed(constant::speed::REAPER_S);
        static school::Skill reap(constant::unit::REAPER, (static_cast<squad::Squad>(unit_12)), 2, 100, 1.0);

        squad::Moral unit_13(squad::moral_type::POLTERGEIST, 0);
        unit_13.set_max_health(constant::max_health::POLTERGEIST_MH);
        unit_13.set_damage_val(constant::damage::POLTERGEIST_DM);
        unit_13.set_defense_val(constant::defense::POLTERGEIST_DF);
        unit_13.set_motivation(constant::motivation::POLTERGEIST_MT);
        unit_13.set_quantity(constant::max_quantity::POLTERGEIST_MQ);
        unit_13.set_experience(constant::experience::POLTERGEIST_EX);
        unit_13.set_name(constant::unit::POLTERGEIST);
        unit_13.set_speed(constant::speed::POLTERGEIST_S);
        static school::Skill polter(constant::unit::POLTERGEIST, (static_cast<squad::Squad>(unit_13)), 0, 30, 1.0);

        squad::Amoral unit_14(squad::amoral_type::TYPHON);
        unit_14.set_max_health(constant::max_health::TYPHON_MH);
        unit_14.set_damage_val(constant::damage::TYPHON_DM);
        unit_14.set_defense_val(constant::defense::TYPHON_DF);
        unit_14.set_motivation(constant::motivation::TYPHON_MT);
        unit_14.set_quantity(constant::max_quantity::TYPHON_MQ);
        unit_14.set_experience(constant::experience::TYPHON_EX);
        unit_14.set_name(constant::unit::TYPHON);
        unit_14.set_speed(constant::speed::TYPHON_S);
        static school::Skill typh(constant::unit::TYPHON, (static_cast<squad::Squad>(unit_14)), 1, 70, 1.0);

        squad::Immortal_moral unit_15(squad::immortal_moral_type::MIMIC);
        unit_15.set_max_health(constant::max_health::MIMIC_MH);
        unit_15.set_damage_val(constant::damage::MIMIC_DM);
        unit_15.set_defense_val(constant::defense::MIMIC_DF);
        unit_15.set_motivation(constant::motivation::MIMIC_MT);
        unit_15.set_quantity(constant::max_quantity::MIMIC_MQ);
        unit_15.set_experience(constant::experience::MIMIC_EX);
        unit_15.set_name(constant::unit::MIMIC);
        unit_15.set_speed(constant::speed::MIMIC_S);
        static school::Skill mimic(constant::unit::MIMIC, (static_cast<squad::Squad>(unit_15)), 2, 100, 1.0);

        //  INIT SCHOOLS

        std::vector<school::Skill> skill_robo = {robo, centry, colos};
        school::School robotics(constant::school_type::ROBOTICS, skill_robo);

        std::vector<school::Skill> skill_energ = {ghost, infest, disrup};
        school::School energiser(constant::school_type::ENERGISER, skill_energ);

        std::vector<school::Skill> skill_par = {elf, gnome, dend};
        school::School parallel(constant::school_type::PARALLEL, skill_par);

        std::vector<school::Skill> skill_bio = {marine, cycl, reap};
        school::School biotech(constant::school_type::BIOTECH, skill_bio);

        std::vector<school::Skill> skill_nano = {polter, typh, mimic};
        school::School nanoslime(constant::school_type::NANOSLIME, skill_nano);

        school_table_type sch_table = {
            {constant::school_type::ROBOTICS, robotics},
            {constant::school_type::ENERGISER, energiser},
            {constant::school_type::PARALLEL, parallel},
            {constant::school_type::BIOTECH, biotech},
            {constant::school_type::NANOSLIME, nanoslime}};

        school_table = sch_table;

        //  INIT LORDS

        std::map<school::School, unsigned> knowledge = {
            {robotics, 0},
            {energiser, 0},
            {parallel, 0},
            {biotech, 0},
            {nanoslime, 0}};

        std::string name_left = "LEFT PLAYER";
        std::string name_right = "RIGHT PLAYER";

        // squad::Lord *player_left;
        // player_left = new squad::Lord(name_left, 100, 1000);
        // player_left->set_knowledge(knowledge);
        // squad::Lord *player_right;
        // player_right = new squad::Lord(name_right, 100, 1000);
        // player_right->set_knowledge(knowledge);

        // list u_list = {player_left, player_right};
        // units_list = u_list;

        //  INIT MAP
    }
}