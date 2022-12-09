#include "../include/school.hpp"

namespace school
{
    School::School(const constant::school_type &new_type)
    {
        type = new_type;
        skill_list = {};
    }

    School::School(const constant::school_type &new_type, const Skill &new_skill)
    {
        type = new_type;
        skill_list = {new_skill};
    }

    School::School(const constant::school_type &new_type, const std::vector<Skill> &new_skill_list)
    {
        type = new_type;
        skill_list = new_skill_list;
    }

    School::School(const School &school)
    {
        type = school.type;
        skill_list = school.skill_list;
    }

    void School::set_type(const constant::school_type &new_type) { type = new_type; }

    void School::set_skill_list(const std::vector<Skill> &new_skill_list) { skill_list = new_skill_list; }

    void School::add_skill(const Skill &new_skill)
    {
        skill_list.insert(skill_list.end(), new_skill);
    }

    constant::school_type School::get_type() const { return type; }

    std::vector<Skill> School::get_skill_list() const { return skill_list; }

    std::strong_ordering School::operator<=>(const School &school) const
    {
        return type <=> school.type;
    }

}