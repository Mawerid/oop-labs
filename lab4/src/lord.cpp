#include "../include/lord.hpp"

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

    void Lord::upgrade_school(const school::School &school)
    {
        unsigned curr_level = knowledge[school];

        auto list = school.get_skill_list();

        unsigned min_energy = list[curr_level - 1].get_energy();

        if (energy >= min_energy)
        {
            knowledge[school]++;
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
                Moral *unit;
                unit = new Moral(squad::moral_type::ROBOMECH, 0);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
            else if (sq_type == 1 && (knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                Amoral *unit;
                unit = new Amoral(squad::amoral_type::CENTRY);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
            else if ((knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                Immortal_amoral *unit;
                unit = new Immortal_amoral(squad::immortal_amoral_type::COLOSSUS);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
        }
        else if (squad_name < 6)
        {
            if (squad_name == 16 || sq_type > knowledge.begin()->second)
                return nullptr;

            if (sq_type == 0 && (knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                Moral *unit;
                unit = new Moral(squad::moral_type::GHOST, 0);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
            else if (sq_type == 1 && (knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                Amoral *unit;
                unit = new Amoral(squad::amoral_type::INFESTOR);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
            else if ((knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                Immortal_amoral *unit;
                unit = new Immortal_amoral(squad::immortal_amoral_type::DISRUPTOR);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
        }
        else if (squad_name < 9)
        {
            if (squad_name == 16 || sq_type > knowledge.begin()->second)
                return nullptr;

            if (sq_type == 0 && (knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                Moral *unit;
                unit = new Moral(squad::moral_type::ELF, 0);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
            else if (sq_type == 1 && (knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                Amoral *unit;
                unit = new Amoral(squad::amoral_type::GNOME);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
            else if ((knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                Immortal_moral *unit;
                unit = new Immortal_moral(squad::immortal_moral_type::DENDRIOD);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
        }
        else if (squad_name < 12)
        {
            if (squad_name == 16 || sq_type > knowledge.begin()->second)
                return nullptr;

            if (sq_type == 0 && (knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                Moral *unit;
                unit = new Moral(squad::moral_type::MARINE, 0);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
            else if (sq_type == 1 && (knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                Amoral *unit;
                unit = new Amoral(squad::amoral_type::CYCLONE);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
            else if ((knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                Immortal_moral *unit;
                unit = new Immortal_moral(squad::immortal_moral_type::REAPER);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
        }
        else
        {
            if (squad_name == 16 || sq_type > knowledge.begin()->second)
                return nullptr;

            if (sq_type == 0 && (knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                Moral *unit;
                unit = new Moral(squad::moral_type::POLTERGEIST, 0);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
            else if (sq_type == 1 && (knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                Amoral *unit;
                unit = new Amoral(squad::amoral_type::TYPHON);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
            else if ((knowledge.begin()->first.get_skill_list())[0].get_energy() <= energy)
            {
                Immortal_moral *unit;
                unit = new Immortal_moral(squad::immortal_moral_type::MIMIC);
                dynamic_cast<squad::Squad *>(unit);
                return unit;
            }
        }
    }
}