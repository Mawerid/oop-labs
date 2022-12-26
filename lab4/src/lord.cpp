#include "../include/lord.hpp"
#include <iostream>

namespace squad
{
    Lord::Lord(std::string &name)
    {
        lord_name = name;
        energy = 0;
        max_energy = 0;
        accum_coef = 1.0;
        knowledge = {{school::School(constant::school_type::ROBOTICS), 0}, {school::School(constant::school_type::ENERGISER), 0}, {school::School(constant::school_type::PARALLEL), 0}, {school::School(constant::school_type::BIOTECH), 0}, {school::School(constant::school_type::NANOSLIME), 0}};
    }

    Lord::Lord(std::string &name, const unsigned &max_nrgy)
    {
        lord_name = name;
        energy = max_energy;
        max_energy = max_energy;
        accum_coef = 1.0;
        knowledge = {{school::School(constant::school_type::ROBOTICS), 0}, {school::School(constant::school_type::ENERGISER), 0}, {school::School(constant::school_type::PARALLEL), 0}, {school::School(constant::school_type::BIOTECH), 0}, {school::School(constant::school_type::NANOSLIME), 0}};
    }

    Lord::Lord(std::string &name, const unsigned &nrgy, const unsigned &max_nrgy)
    {
        lord_name = name;
        energy = nrgy;
        max_energy = max_nrgy;
        accum_coef = 1.0;
        knowledge = {{school::School(constant::school_type::ROBOTICS), 0}, {school::School(constant::school_type::ENERGISER), 0}, {school::School(constant::school_type::PARALLEL), 0}, {school::School(constant::school_type::BIOTECH), 0}, {school::School(constant::school_type::NANOSLIME), 0}};
    }

    std::string Lord::get_name() { return lord_name; }

    unsigned Lord::get_energy() { return energy; }

    unsigned Lord::get_max_energy() { return max_energy; }

    double Lord::get_accum_coef() { return accum_coef; }

    std::map<school::School, unsigned> Lord::get_knowledge() { return knowledge; }

    void Lord::set_name(const std::string &name) { lord_name = name; }

    void Lord::set_energy(const unsigned &nrgy) { energy = nrgy; }

    void Lord::set_max_energy(const unsigned &max_nrgy) { max_energy = max_nrgy; }

    void Lord::set_accum_coef(const double &coef) { accum_coef = coef; }

    void Lord::set_knowledge(const std::map<school::School, unsigned> &new_knowledge) { knowledge = new_knowledge; }

    void Lord::upgrade_school(const constant::school_type &school_t)
    {
        auto school = knowledge.begin();

        for(; school->first.get_type()!=school_t; school++);

        unsigned curr_level = school->second;

        auto list = school->first.get_skill_list();

        unsigned min_energy = list[curr_level].get_energy();

        if (energy >= min_energy)
        {
            (school->second)++;
            energy -= min_energy;
        }
    }

    Squad *Lord::call_squad(const constant::unit &squad_name)
    {
        unsigned sq_type = squad_name % 3;

        if (squad_name < 3)
        {
            if (squad_name == 16 || sq_type > knowledge.begin()->second)
                return nullptr;

            if (sq_type == 0 && (knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                energy -= (knowledge.begin()->first.get_skill_list())[0].get_energy();
                Moral *unit;
                unit = new Moral(squad::moral_type::ROBOMECH, 0);
                unit->set_max_health((unsigned)((int)constant::max_health::ROBOMECH_MH * accum_coef));
                unit->set_damage_val(constant::damage::ROBOMECH_DM);
                unit->set_defense_val(constant::defense::ROBOMECH_DF);
                unit->set_motivation(constant::motivation::ROBOMECH_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::ROBOMECH_MQ * accum_coef));
                unit->set_experience(constant::experience::ROBOMECH_EX);
                unit->set_name(constant::unit::ROBOMECH);
                unit->set_speed(constant::speed::ROBOMECH_S);
                return static_cast<squad::Squad *>(unit);
            }
            else if (sq_type == 1 && (knowledge.begin()->first.get_skill_list())[1].get_energy() <= energy)
            {
                energy -= (knowledge.begin()->first.get_skill_list())[1].get_energy();
                Amoral *unit;
                unit = new Amoral(squad::amoral_type::CENTRY);
                unit->set_max_health((unsigned)((int)constant::max_health::CENTRY_MH * accum_coef));
                unit->set_damage_val(constant::damage::CENTRY_DM);
                unit->set_defense_val(constant::defense::CENTRY_DF);
                unit->set_motivation(constant::motivation::CENTRY_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::CENTRY_MQ * accum_coef));
                unit->set_experience(constant::experience::CENTRY_EX);
                unit->set_name(constant::unit::CENTRY);
                unit->set_speed(constant::speed::CENTRY_S);
                return static_cast<squad::Squad *>(unit);
            }
            else if ((knowledge.begin()->first.get_skill_list())[2].get_energy() <= energy)
            {
                energy -= (knowledge.begin()->first.get_skill_list())[2].get_energy();
                Immortal_amoral *unit;
                unit = new Immortal_amoral(squad::immortal_amoral_type::COLOSSUS);
                unit->set_max_health((unsigned)((int)constant::max_health::COLOSSUS_MH * accum_coef));
                unit->set_damage_val(constant::damage::COLOSSUS_DM);
                unit->set_defense_val(constant::defense::COLOSSUS_DF);
                unit->set_motivation(constant::motivation::COLOSSUS_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::COLOSSUS_MQ * accum_coef));
                unit->set_experience(constant::experience::COLOSSUS_EX);
                unit->set_name(constant::unit::COLOSSUS);
                unit->set_speed(constant::speed::COLOSSUS_S);
                return static_cast<squad::Squad *>(unit);
            }
        }
        else if (squad_name < 6)
        {
            if (squad_name == 16 || sq_type > knowledge.begin()->second)
                return nullptr;

            if (sq_type == 0 && ((knowledge.begin()++)->first.get_skill_list())[0].get_energy() <= energy)
            {
                energy -= ((knowledge.begin()++)->first.get_skill_list())[0].get_energy();
                Moral *unit;
                unit = new Moral(squad::moral_type::GHOST, 0);
                unit->set_max_health((unsigned)((int)constant::max_health::GHOST_MH * accum_coef));
                unit->set_damage_val(constant::damage::GHOST_DM);
                unit->set_defense_val(constant::defense::GHOST_DF);
                unit->set_motivation(constant::motivation::GHOST_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::GHOST_MQ * accum_coef));
                unit->set_experience(constant::experience::GHOST_EX);
                unit->set_name(constant::unit::GHOST);
                unit->set_speed(constant::speed::GHOST_S);
                return static_cast<squad::Squad *>(unit);
            }
            else if (sq_type == 1 && ((knowledge.begin()++)->first.get_skill_list())[1].get_energy() <= energy)
            {
                energy -= ((knowledge.begin()++)->first.get_skill_list())[1].get_energy();
                Amoral *unit;
                unit = new Amoral(squad::amoral_type::INFESTOR);
                unit->set_max_health((unsigned)((int)constant::max_health::INFESTOR_MH * accum_coef));
                unit->set_damage_val(constant::damage::INFESTOR_DM);
                unit->set_defense_val(constant::defense::INFESTOR_DF);
                unit->set_motivation(constant::motivation::INFESTOR_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::INFESTOR_MQ * accum_coef));
                unit->set_experience(constant::experience::INFESTOR_EX);
                unit->set_name(constant::unit::INFESTOR);
                unit->set_speed(constant::speed::INFESTOR_S);
                return static_cast<squad::Squad *>(unit);
            }
            else if (((knowledge.begin()++)->first.get_skill_list())[2].get_energy() <= energy)
            {
                energy -= ((knowledge.begin()++)->first.get_skill_list())[2].get_energy();
                Immortal_amoral *unit;
                unit = new Immortal_amoral(squad::immortal_amoral_type::DISRUPTOR);
                unit->set_max_health((unsigned)((int)constant::max_health::DISRUPTOR_MH * accum_coef));
                unit->set_damage_val(constant::damage::DISRUPTOR_DM);
                unit->set_defense_val(constant::defense::DISRUPTOR_DF);
                unit->set_motivation(constant::motivation::DISRUPTOR_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::DISRUPTOR_MQ * accum_coef));
                unit->set_experience(constant::experience::DISRUPTOR_EX);
                unit->set_name(constant::unit::DISRUPTOR);
                unit->set_speed(constant::speed::DISRUPTOR_S);
                return static_cast<squad::Squad *>(unit);
            }
        }
        else if (squad_name < 9)
        {
            if (squad_name == 16 || sq_type > knowledge.begin()->second)
                return nullptr;

            if (sq_type == 0 && (((knowledge.begin()++)++)->first.get_skill_list())[0].get_energy() <= energy)
            {
                energy -= (((knowledge.begin()++)++)->first.get_skill_list())[0].get_energy();
                Moral *unit;
                unit = new Moral(squad::moral_type::ELF, 0);
                unit->set_max_health((unsigned)((int)constant::max_health::ELF_MH * accum_coef));
                unit->set_damage_val(constant::damage::ELF_DM);
                unit->set_defense_val(constant::defense::ELF_DF);
                unit->set_motivation(constant::motivation::ELF_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::ELF_MQ * accum_coef));
                unit->set_experience(constant::experience::ELF_EX);
                unit->set_name(constant::unit::ELF);
                unit->set_speed(constant::speed::ELF_S);
                return static_cast<squad::Squad *>(unit);
            }
            else if (sq_type == 1 && (((knowledge.begin()++)++)->first.get_skill_list())[1].get_energy() <= energy)
            {
                energy -= (((knowledge.begin()++)++)->first.get_skill_list())[1].get_energy();
                Amoral *unit;
                unit = new Amoral(squad::amoral_type::GNOME);
                unit->set_max_health((unsigned)((int)constant::max_health::GNOME_MH * accum_coef));
                unit->set_damage_val(constant::damage::GNOME_DM);
                unit->set_defense_val(constant::defense::GNOME_DF);
                unit->set_motivation(constant::motivation::GNOME_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::GNOME_MQ * accum_coef));
                unit->set_experience(constant::experience::GNOME_EX);
                unit->set_name(constant::unit::GNOME);
                unit->set_speed(constant::speed::GNOME_S);
                return static_cast<squad::Squad *>(unit);
            }
            else if ((((knowledge.begin()++)++)->first.get_skill_list())[2].get_energy() <= energy)
            {
                energy -= (((knowledge.begin()++)++)->first.get_skill_list())[2].get_energy();
                Immortal_moral *unit;
                unit = new Immortal_moral(squad::immortal_moral_type::DENDRIOD);
                unit->set_max_health((unsigned)((int)constant::max_health::DENDRIOD_MH * accum_coef));
                unit->set_damage_val(constant::damage::DENDRIOD_DM);
                unit->set_defense_val(constant::defense::DENDRIOD_DF);
                unit->set_motivation(constant::motivation::DENDRIOD_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::DENDRIOD_MQ * accum_coef));
                unit->set_experience(constant::experience::DENDRIOD_EX);
                unit->set_name(constant::unit::DENDRIOD);
                unit->set_speed(constant::speed::DENDRIOD_S);
                return static_cast<squad::Squad *>(unit);
            }
        }
        else if (squad_name < 12)
        {
            if (squad_name == 16 || sq_type > knowledge.begin()->second)
                return nullptr;

            if (sq_type == 0 && ((((knowledge.begin()++)++)++)->first.get_skill_list())[0].get_energy() <= energy)
            {
                energy -= ((((knowledge.begin()++)++)++)->first.get_skill_list())[0].get_energy();
                Moral *unit;
                unit = new Moral(squad::moral_type::MARINE, 0);
                unit->set_max_health((unsigned)((int)constant::max_health::MARINE_MH * accum_coef));
                unit->set_damage_val(constant::damage::MARINE_DM);
                unit->set_defense_val(constant::defense::MARINE_DF);
                unit->set_motivation(constant::motivation::MARINE_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::MARINE_MQ * accum_coef));
                unit->set_experience(constant::experience::MARINE_EX);
                unit->set_name(constant::unit::MARINE);
                unit->set_speed(constant::speed::MARINE_S);
                return static_cast<squad::Squad *>(unit);
            }
            else if (sq_type == 1 && ((((knowledge.begin()++)++)++)->first.get_skill_list())[1].get_energy() <= energy)
            {
                energy -= ((((knowledge.begin()++)++)++)->first.get_skill_list())[1].get_energy();
                Amoral *unit;
                unit = new Amoral(squad::amoral_type::CYCLONE);
                unit->set_max_health((unsigned)((int)constant::max_health::CYCLONE_MH * accum_coef));
                unit->set_damage_val(constant::damage::CYCLONE_DM);
                unit->set_defense_val(constant::defense::CYCLONE_DF);
                unit->set_motivation(constant::motivation::CYCLONE_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::CYCLONE_MQ * accum_coef));
                unit->set_experience(constant::experience::CYCLONE_EX);
                unit->set_name(constant::unit::CYCLONE);
                unit->set_speed(constant::speed::CYCLONE_S);
                return static_cast<squad::Squad *>(unit);
            }
            else if (((((knowledge.begin()++)++)++)->first.get_skill_list())[2].get_energy() <= energy)
            {
                energy -= ((((knowledge.begin()++)++)++)->first.get_skill_list())[2].get_energy();
                Immortal_moral *unit;
                unit = new Immortal_moral(squad::immortal_moral_type::REAPER);
                unit->set_max_health((unsigned)((int)constant::max_health::REAPER_MH * accum_coef));
                unit->set_damage_val(constant::damage::REAPER_DM);
                unit->set_defense_val(constant::defense::REAPER_DF);
                unit->set_motivation(constant::motivation::REAPER_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::REAPER_MQ * accum_coef));
                unit->set_experience(constant::experience::REAPER_EX);
                unit->set_name(constant::unit::REAPER);
                unit->set_speed(constant::speed::REAPER_S);
                return static_cast<squad::Squad *>(unit);
            }
        }
        else
        {
            if (squad_name == 16 || sq_type > knowledge.begin()->second)
                return nullptr;

            if (sq_type == 0 && (((((knowledge.begin()++)++)++)++)->first.get_skill_list())[0].get_energy() <= energy)
            {
                energy -= (((((knowledge.begin()++)++)++)++)->first.get_skill_list())[0].get_energy();
                Moral *unit;
                unit = new Moral(squad::moral_type::POLTERGEIST, 0);
                unit->set_max_health((unsigned)((int)constant::max_health::POLTERGEIST_MH * accum_coef));
                unit->set_damage_val(constant::damage::POLTERGEIST_DM);
                unit->set_defense_val(constant::defense::POLTERGEIST_DF);
                unit->set_motivation(constant::motivation::POLTERGEIST_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::POLTERGEIST_MQ * accum_coef));
                unit->set_experience(constant::experience::POLTERGEIST_EX);
                unit->set_name(constant::unit::POLTERGEIST);
                unit->set_speed(constant::speed::POLTERGEIST_S);
                return static_cast<squad::Squad *>(unit);
            }
            else if (sq_type == 1 && (((((knowledge.begin()++)++)++)++)->first.get_skill_list())[1].get_energy() <= energy)
            {
                energy -= (((((knowledge.begin()++)++)++)++)->first.get_skill_list())[1].get_energy();
                Amoral *unit;
                unit = new Amoral(squad::amoral_type::TYPHON);
                unit->set_max_health((unsigned)((int)constant::max_health::TYPHON_MH * accum_coef));
                unit->set_damage_val(constant::damage::TYPHON_DM);
                unit->set_defense_val(constant::defense::TYPHON_DF);
                unit->set_motivation(constant::motivation::TYPHON_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::TYPHON_MQ * accum_coef));
                unit->set_experience(constant::experience::TYPHON_EX);
                unit->set_name(constant::unit::TYPHON);
                unit->set_speed(constant::speed::TYPHON_S);
                return static_cast<squad::Squad *>(unit);
            }
            else if ((((((knowledge.begin()++)++)++)++)->first.get_skill_list())[2].get_energy() <= energy)
            {
                energy -= (((((knowledge.begin()++)++)++)++)->first.get_skill_list())[2].get_energy();
                Immortal_moral *unit;
                unit = new Immortal_moral(squad::immortal_moral_type::MIMIC);
                unit->set_max_health((unsigned)((int)constant::max_health::MIMIC_MH * accum_coef));
                unit->set_damage_val(constant::damage::MIMIC_DM);
                unit->set_defense_val(constant::defense::MIMIC_DF);
                unit->set_motivation(constant::motivation::MIMIC_MT);
                unit->set_quantity((unsigned)((int)constant::max_quantity::MIMIC_MQ * accum_coef));
                unit->set_experience(constant::experience::MIMIC_EX);
                unit->set_name(constant::unit::MIMIC);
                unit->set_speed(constant::speed::MIMIC_S);
                return static_cast<squad::Squad *>(unit);
            }
        }

        return nullptr;
    }
}