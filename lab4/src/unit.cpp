#include "../include/unit.hpp"

namespace squad {
Unit::Unit(const constant::unit &name) : Squad(name), damage_(0), shield_(0) {}

Unit::Unit(const constant::unit &name, const unsigned &damage,
           const unsigned &shield) : Squad(name),
                                     damage_(damage),
                                     shield_(shield) {}

Unit::Unit(const Unit &squad) : Squad(squad.name_),
                                damage_(squad.damage_),
                                shield_(squad.shield_) {}

Unit::Unit(Unit &&squad) : Squad(squad.name_),
                           damage_(squad.damage_),
                           shield_(squad.shield_) {}

unsigned Unit::get_damage_val() const { return damage_; }

unsigned Unit::get_defense_val() const { return shield_; }

void Unit::set_damage_val(const unsigned &damage) { damage_ = damage; }

void Unit::set_defense_val(const unsigned &shield) { shield_ = shield; }

bool Unit::operator==(const Unit &squad) {
    if (motivation_ == squad.motivation_ && health_ == squad.health_ &&
        max_health_ == squad.max_health_ && quantity_ == squad.quantity_ &&
        speed_ == squad.speed_ && experience_ == squad.experience_ &&
        team_ == squad.team_ && name_ == squad.name_ &&
        damage_ == squad.damage_ && shield_ == squad.shield_)
        return true;
    else
        return false;
}

bool Unit::operator!=(const Unit &squad) {
    return !(*this == squad);
}

}  // namespace squad