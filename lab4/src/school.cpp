#include "../include/school.hpp"

#include <stdexcept>

namespace school {

School::School(const constant::school_type &type) : type_(type) {
    list new_list = {};

    for (int i = 0; i < UNITS_PER_SCHOOL; i++) {
        auto name = static_cast<constant::unit>(type * 3 + i);

        Skill::unit_list easy_kill = {
            static_cast<constant::unit>(
                (name + UNITS_PER_SCHOOL) % UNITS_COUNT),
            static_cast<constant::unit>(
                (name + UNITS_PER_SCHOOL * 2) % UNITS_COUNT)};

        Skill skill = Skill(name, i, constant::energy[name], 1.0, easy_kill);
        new_list.insert(new_list.end(), skill);
    }

    skill_list_ = new_list;
}

School::School(const constant::school_type &type,
               const list &skill_list) : type_(type),
                                         skill_list_(skill_list) {}

void School::set_type(const constant::school_type &type) { type_ = type; }

void School::set_skill_list(const list &skill_list) {
    skill_list_ = skill_list;
}

void School::add_skill(const Skill &skill) {
    skill_list_.insert(skill_list_.end(), skill);
}

void School::remove_skill(const Skill &skill) {
    size_t i = 0;
    for (; skill_list_[i] != skill; i++)
        ;

    skill_list_.erase(skill_list_.begin() + i);
}

bool School::check_skill(const constant::unit &skill_name) {
    size_t i = 0;
    for (; skill_list_[i].get_name() != skill_name && i < skill_list_.size(); i++)
        ;

    if (i < skill_list_.size() && skill_list_[i].get_name() == skill_name)
        return true;
    else
        return false;
}

Skill School::get_skill(const constant::unit &skill_name) {
    for (auto &it : skill_list_)
        if (it.get_name() == skill_name)
            return it;
    throw std::invalid_argument("no such skill in this school");
}

constant::school_type School::get_type() const { return type_; }

School::list School::get_skill_list() const { return skill_list_; }

bool School::operator==(const School &school) const {
    if (type_ == school.type_ && skill_list_ == school.skill_list_)
        return true;
    else
        return false;
}

bool School::operator!=(const School &school) const {
    return !(*this == school);
}

bool School::operator<(const School &school) const {
    if (type_ < school.type_)
        return true;
    else
        return false;
}

bool School::operator>(const School &school) const {
    if (type_ > school.type_)
        return true;
    else
        return false;
}

bool School::operator<=(const School &school) const {
    return !(*this > school);
}

bool School::operator>=(const School &school) const {
    return !(*this < school);
}

}  // namespace school