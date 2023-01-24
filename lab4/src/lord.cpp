#include "../include/lord.hpp"

#include <iostream>
#include <stdexcept>

namespace squad {
Lord::Lord(std::string &name, const unsigned &team)
    : Squad(constant::unit::LORD, team),
      lord_name_(name),
      energy_(START_ENERGY),
      max_energy_(START_MAX_ENERGY),
      accum_coefficient_(1.0) {
    knowledge_type tmp = {
        {school::School(constant::school_type::ROBOTICS), 0},
        {school::School(constant::school_type::ENERGISER), 0},
        {school::School(constant::school_type::PARALLEL), 0},
        {school::School(constant::school_type::BIOTECH), 0},
        {school::School(constant::school_type::NANOSLIME), 0}};

    knowledge_ = tmp;
}

std::string Lord::get_lord_name() const { return lord_name_; }

unsigned Lord::get_energy() const { return energy_; }

unsigned Lord::get_max_energy() const { return max_energy_; }

double Lord::get_accum_coefficient() const { return accum_coefficient_; }

Lord::knowledge_type Lord::get_knowledge() const { return knowledge_; }

void Lord::set_lord_name(const std::string &name) { lord_name_ = name; }

void Lord::set_energy(const unsigned &energy) { energy_ = energy; }

void Lord::set_max_energy(const unsigned &max_energy) {
    max_energy_ = max_energy;
}

void Lord::set_accum_coefficient(const double &accum_coefficient) {
    accum_coefficient_ = accum_coefficient;
}

void Lord::set_knowledge(const Lord::knowledge_type &knowledge) {
    knowledge_ = knowledge;
}

void Lord::upgrade_school(const constant::school_type &school_type) {
    auto school = knowledge_.begin();
    for (; school->first.get_type() != school_type; school++)
        ;

    unsigned curr_level = school->second;
    auto list = school->first.get_skill_list();
    unsigned min_energy = list[curr_level].get_energy() * COEF_MIN_STUDY;

    if (experience_ >= min_energy) {
        (school->second)++;
        experience_ -= min_energy;
    } else
        throw std::invalid_argument("not enough experience");
}

auto find_school(Lord::knowledge_type knowledge, constant::school_type type) {
    for (auto iter : knowledge)
        if (iter.first.get_type() == type)
            return iter;
    throw std::invalid_argument("No such school");
}

Squad *Lord::call_squad(const constant::unit &name) {
    if (name == constant::unit::LORD)
        throw std::invalid_argument("You cannot call one more lord");

    auto type = static_cast<constant::school_type>(name / UNITS_PER_SCHOOL);
    size_t skill = name % UNITS_PER_SCHOOL;
    auto tmp = find_school(knowledge_, type);
    auto skill_list = tmp.first.get_skill_list();
    unsigned level = tmp.second;

    std::string moral = "M";
    std::string amoral = "A";
    std::string imm_moral = "IM";
    std::string imm_amoral = "IA";

    if (skill_list[skill].get_minimal_study() > level)
        throw std::invalid_argument("Not enough level");

    if (skill_list[skill].get_energy() > energy_)
        throw std::invalid_argument("Not enough energy");

    if (constant::unit_type[name] == moral) {
        moral_type type = convert_to_moral(name);
        Moral *squad = new Moral(type);
        energy_ -= skill_list[skill].get_energy();
        squad->set_team(team_);
        return squad;
    } else if (constant::unit_type[name] == amoral) {
        amoral_type type = convert_to_amoral(name);
        Amoral *squad = new Amoral(type);
        energy_ -= skill_list[skill].get_energy();
        squad->set_team(team_);
        return squad;
    } else if (constant::unit_type[name] == imm_moral) {
        immortal_moral_type type = convert_to_immortal_moral(name);
        Immortal_moral *squad = new Immortal_moral(type);
        energy_ -= skill_list[skill].get_energy();
        squad->set_team(team_);
        return squad;
    } else if (constant::unit_type[name] == imm_amoral) {
        immortal_amoral_type type = convert_to_immortal_amoral(name);
        Immortal_amoral *squad = new Immortal_amoral(type);
        energy_ -= skill_list[skill].get_energy();
        squad->set_team(team_);
        return squad;

    } else
        throw std::invalid_argument("You cannot call this");

    return nullptr;
}

void Lord::modify_energy(const int &energy) {
    energy_ += energy;
}

void Lord::modify_experience(const unsigned &experience) {
    experience_ += experience;
}

bool Lord::operator==(const Lord &lord) const {
    if (motivation_ == lord.motivation_ && health_ == lord.health_ &&
        max_health_ == lord.max_health_ && quantity_ == lord.quantity_ &&
        speed_ == lord.speed_ && experience_ == lord.experience_ &&
        team_ == lord.team_ && name_ == lord.name_ &&
        lord_name_ == lord.lord_name_ && energy_ == lord.energy_ &&
        max_energy_ == lord.max_energy_ &&
        accum_coefficient_ == lord.accum_coefficient_ &&
        knowledge_ == lord.knowledge_)
        return true;
    else
        return false;
}

bool Lord::operator!=(const Lord &lord) const {
    return !(*this == lord);
}
}  // namespace squad