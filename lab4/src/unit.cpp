#include "../include/unit.hpp"

namespace squad {
Unit::Unit(const constant::unit &name) : Squad(name), damage_(0), shield_(0) {}

Unit::Unit(const constant::unit &name, const unsigned &damage,
           const unsigned &shield) : Squad(name),
                                     damage_(damage),
                                     shield_(shield) {}

unsigned Unit::get_damage_val() const { return damage_; }

unsigned Unit::get_defense_val() const { return shield_; }

void Unit::set_damage_val(const unsigned &damage) { damage_ = damage; }

void Unit::set_defense_val(const unsigned &shield) { shield_ = shield; }

}  // namespace squad