#include "../include/skill.hpp"

namespace school
{

    Skill::Skill()
    {
    }

    Skill::Skill(const squad::Squad &new_decs)
    {
    }

    Skill::Skill(const constant::unit &new_name)
    {
    }

    Skill::Skill(const constant::unit &new_name, const squad::Squad &new_decs, const unsigned &study, const unsigned &nrgy, const double &coef)
    {
    }

    Skill::Skill(const Skill &skill)
    {
    }

    void Skill::set_name(const constant::unit &new_name)
    {
    }

    void Skill::set_desc(const squad::Squad &new_decs)
    {
    }

    void Skill::set_min_study(const unsigned &new_study)
    {
    }

    void Skill::set_energy(const unsigned &nrgy)
    {
    }

    void Skill::set_count_coef(const unsigned &new_coef)
    {
    }

    void Skill::set_easy_kill(const std::vector<constant::unit> &new_list)
    {
    }

    constant::unit Skill::get_name() const
    {
    }

    squad::Squad Skill::get_desc() const
    {
    }

    unsigned Skill::get_min_study() const
    {
    }

    unsigned Skill::get_energy() const
    {
    }

    unsigned Skill::get_count_coef() const
    {
    }

    std::vector<constant::unit> Skill::get_easy_kill() const
    {
    }

    void Skill::add_easy_kill(const constant::unit &new_name)
    {
    }

    void Skill::remove_easy_kill(const constant::unit &new_name)
    {
    }

    bool Skill::check_easy_kill(const constant::unit &new_name)
    {
    }
}