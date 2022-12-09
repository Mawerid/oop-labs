#include "../include/skill.hpp"

namespace school
{

    Skill::Skill()
    {
        name = constant::unit::ROBOMECH;
        desc = constant::unit::ROBOMECH;
        min_study = constant::experience::ROBOMECH_EX;
        energy = 0;
        count_coef = 1.0;
        easy_kill = {};
    }

    Skill::Skill(const squad::Squad &new_decs)
    {
        desc = new_decs;
        name = new_decs.get_name();
        min_study = constant::experience::ROBOMECH_EX;
        energy = 0;
        count_coef = 1.0;
        easy_kill = {};
    }

    Skill::Skill(const constant::unit &new_name)
    {
        name = new_name;
        desc = constant::unit::ROBOMECH;
        min_study = constant::experience::ROBOMECH_EX;
        energy = 0;
        count_coef = 1.0;
        easy_kill = {};
    }

    Skill::Skill(const constant::unit &new_name, const squad::Squad &new_decs, const unsigned &study, const unsigned &nrgy, const double &coef)
    {
        name = new_name;
        desc = new_decs;
        min_study = study;
        energy = nrgy;
        count_coef = coef;
        easy_kill = {};
    }

    Skill::Skill(const Skill &skill)
    {
        name = skill.name;
        desc = skill.desc;
        min_study = skill.min_study;
        energy = skill.energy;
        count_coef = skill.count_coef;
        easy_kill = skill.easy_kill;
    }

    void Skill::set_name(const constant::unit &new_name) { name = new_name; }

    void Skill::set_desc(const squad::Squad &new_decs) { desc = new_decs; }

    void Skill::set_min_study(const unsigned &new_study) { min_study = new_study; }

    void Skill::set_energy(const unsigned &nrgy) { energy = nrgy; }

    void Skill::set_count_coef(const double &new_coef) { count_coef = new_coef; }

    void Skill::set_easy_kill(const std::vector<constant::unit> &new_list) { easy_kill = new_list; }

    constant::unit Skill::get_name() const { return name; }

    squad::Squad Skill::get_desc() const { return desc; }

    unsigned Skill::get_min_study() const { return min_study; }

    unsigned Skill::get_energy() const { return energy; }

    unsigned Skill::get_count_coef() const { return count_coef; }

    std::vector<constant::unit> Skill::get_easy_kill() const { return easy_kill; }

    void Skill::add_easy_kill(const constant::unit &new_name)
    {
        easy_kill.insert(easy_kill.end(), new_name);
    }

    void Skill::remove_easy_kill(const constant::unit &new_name)
    {
        size_t i = 0;

        for (; easy_kill[i] != new_name; i++)
            ;

        easy_kill.erase(easy_kill.begin() + i);
    }

    bool Skill::check_easy_kill(const constant::unit &new_name)
    {
        size_t i = 0;
        for (; easy_kill[i] != new_name; i++)
            ;

        if (easy_kill[i] == new_name)
            return true;
        else
            return false;
    }
}