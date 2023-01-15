#include "../include/skill.hpp"

#include <iostream>

namespace school {

Skill::Skill(const constant::unit &name,
             const unsigned &minimal_study,
             const unsigned &energy,
             const double &count_coefficient) : name_(name),
                                                minimal_study_(minimal_study),
                                                energy_(energy),
                                                count_coefficient_(count_coefficient),
                                                easy_kill_({}) {}

Skill::Skill(const constant::unit &name, const unsigned &minimal_study,
             const unsigned &energy, const double &count_coefficient,
             const unit_list easy_kill) : name_(name),
                                          minimal_study_(minimal_study),
                                          energy_(energy),
                                          count_coefficient_(count_coefficient),
                                          easy_kill_(easy_kill) {}

void Skill::set_name(const constant::unit &name) { name_ = name; }

void Skill::set_minimal_study(const unsigned &minimal_study) {
    minimal_study_ = minimal_study;
}

void Skill::set_energy(const unsigned &energy) { energy_ = energy; }

void Skill::set_count_coefficient(const double &count_coefficient) {
    count_coefficient_ = count_coefficient;
}

void Skill::set_easy_kill(const unit_list &list) { easy_kill_ = list; }

constant::unit Skill::get_name() const { return name_; }

unsigned Skill::get_minimal_study() const { return minimal_study_; }

unsigned Skill::get_energy() const { return energy_; }

double Skill::get_count_coefficient() const { return count_coefficient_; }

Skill::unit_list Skill::get_easy_kill() const { return easy_kill_; }

void Skill::add_easy_kill(const constant::unit &name) {
    easy_kill_.insert(easy_kill_.end(), name);
}

void Skill::remove_easy_kill(const constant::unit &name) {
    size_t i = 0;
    for (; easy_kill_[i] != name; i++)
        ;

    easy_kill_.erase(easy_kill_.begin() + i);
}

bool Skill::check_easy_kill(const constant::unit &name) {
    size_t i = 0;
    for (; easy_kill_[i] != name && i < easy_kill_.size(); i++)
        ;

    if (i < easy_kill_.size() && easy_kill_[i] == name)
        return true;
    else
        return false;
}

bool Skill::operator==(const Skill &skill) const {
    if (name_ == skill.name_ &&
        minimal_study_ == skill.minimal_study_ &&
        energy_ == skill.name_ &&
        count_coefficient_ == skill.count_coefficient_ &&
        easy_kill_ == skill.easy_kill_)
        return true;
    else
        return false;
}

bool Skill::operator!=(const Skill &skill) const {
    return !(*this == skill);
}

}  // namespace school