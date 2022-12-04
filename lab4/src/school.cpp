#include "../include/school.hpp"

namespace school
{
    School::School(const constant::school_type &new_type)
    {
    }

    School::School(const constant::school_type &new_type, const Skill &new_skill)
    {
    }

    School::School(const constant::school_type &new_type, const std::list<Skill> &new_skill_list)
    {
    }

    School::School(const School &school)
    {
    }

    void School::set_type(const constant::school_type &new_type) { type = new_type; }

    void School::set_skill_list(const std::list<Skill> &new_skill_list) { skill_list = new_skill_list; }

    void School::add_skill(const Skill &new_skill)
    {
    }

    constant::school_type School::get_type() const { return type; }

    std::list<Skill> School::get_skill_list() const { return skill_list; }
}