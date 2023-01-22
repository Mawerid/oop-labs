#include "../include/common_units.hpp"

namespace squad {

// Amoral

amoral_type convert_to_amoral(const constant::unit &name) {
    switch (name) {
        case constant::unit::CENTRY:
            return amoral_type::CENTRY;
            break;
        case constant::unit::INFESTOR:
            return amoral_type::INFESTOR;
            break;
        case constant::unit::GNOME:
            return amoral_type::GNOME;
            break;
        case constant::unit::CYCLONE:
            return amoral_type::CYCLONE;
            break;
        case constant::unit::TYPHON:
            return amoral_type::TYPHON;
            break;
        default:
            return amoral_type::NONE;
            break;
    }
}

constant::unit Amoral::convert_name(const amoral_type &type) const {
    return static_cast<constant::unit>(static_cast<int>(type) * 3 + 1);
}

Amoral::Amoral(const amoral_type &type)
    : Unit(convert_name(type)), type_(type) {}

Amoral::Amoral(const constant::unit &type) : Unit(type),
                                             type_(amoral_type::NONE) {}

Amoral::Amoral(const Amoral &squad) : Unit(convert_name(squad.type_)),
                                      type_(squad.type_) {}

Amoral::Amoral(Amoral &&squad) : Unit(convert_name(squad.type_)),
                                 type_(squad.type_) {}

amoral_type Amoral::get_type() const { return type_; }

void Amoral::set_type(const amoral_type &type) { type_ = type; }

void Amoral::attack(Squad &squad) const {
    unsigned damage = damage_ * quantity_;
    squad.get_damage(damage);
}

void Amoral::defence(Squad &squad) {
    auto unit = squad.get_name();
    unsigned damage = 0;
    if (unit % 3 == 1 || unit == 2 || unit == 5)
        damage = static_cast<Amoral &>(squad).get_damage_val();
    else if (unit % 3 == 0 || unit == 14 || unit == 11)
        damage = static_cast<Moral &>(squad).get_damage_val();
    this->get_damage(damage);
}

bool Amoral::operator==(const Amoral &squad) const {
    if (motivation_ == squad.motivation_ && health_ == squad.health_ &&
        max_health_ == squad.max_health_ && quantity_ == squad.quantity_ &&
        speed_ == squad.speed_ && experience_ == squad.experience_ &&
        team_ == squad.team_ && name_ == squad.name_ &&
        damage_ == squad.damage_ && shield_ == squad.shield_ &&
        type_ == squad.type_)
        return true;
    else
        return false;
}

bool Amoral::operator!=(const Amoral &squad) const {
    return !(*this == squad);
}

// Moral

moral_type convert_to_moral(const constant::unit &name) {
    switch (name) {
        case constant::unit::ROBOMECH:
            return moral_type::ROBOMECH;
            break;
        case constant::unit::GHOST:
            return moral_type::GHOST;
            break;
        case constant::unit::ELF:
            return moral_type::ELF;
            break;
        case constant::unit::MARINE:
            return moral_type::MARINE;
            break;
        case constant::unit::POLTERGEIST:
            return moral_type::POLTERGEIST;
            break;
        default:
            return moral_type::NONE;
            break;
    }
}

constant::unit Moral::convert_name(const moral_type &type) const {
    return static_cast<constant::unit>(static_cast<int>(type) * 3);
}

Moral::Moral(const moral_type &type) : Unit(convert_name(type)),
                                       type_(type),
                                       moral_(0) {}

Moral::Moral(const constant::unit &type) : Unit(type),
                                           type_(moral_type::NONE),
                                           moral_(0) {}

Moral::Moral(const moral_type &type,
             const int &moral) : Unit(convert_name(type)),
                                 type_(type),
                                 moral_(moral) {}

Moral::Moral(const constant::unit &type,
             const int &moral) : Unit(type),
                                 type_(moral_type::NONE),
                                 moral_(moral) {}

Moral::Moral(const Moral &squad) : Unit(convert_name(squad.type_)),
                                   type_(squad.type_),
                                   moral_(squad.moral_) {}

Moral::Moral(Moral &&squad) : Unit(convert_name(squad.type_)),
                              type_(squad.type_),
                              moral_(squad.moral_) {}

moral_type Moral::get_type() const { return type_; }

int Moral::get_moral() const { return moral_; }

void Moral::set_type(const moral_type &type) { type_ = type; }

void Moral::set_moral(const int &moral) { moral_ = moral; }

void Moral::attack(Squad &squad) const {
    unsigned damage = damage_ * quantity_ + moral_;
    squad.get_damage(damage);
}

void Moral::defence(Squad &squad) {
    auto unit = squad.get_name();
    int damage = (-1) * moral_;
    if (unit % 3 == 1 || unit == 2 || unit == 5)
        damage += static_cast<Amoral &>(squad).get_damage_val();
    else if (unit % 3 == 0 || unit == 14 || unit == 11)
        damage += static_cast<Moral &>(squad).get_damage_val();
    if (damage > 0)
        this->get_damage(static_cast<unsigned>(damage));
}

void Moral::balance_moral() {
    if (moral_ > 0)
        moral_--;
    else if (moral_ < 0)
        moral_++;
}

void Moral::modify_moral(const int &modify) { moral_ += modify; }

bool Moral::operator==(const Moral &squad) const {
    if (motivation_ == squad.motivation_ && health_ == squad.health_ &&
        max_health_ == squad.max_health_ && quantity_ == squad.quantity_ &&
        speed_ == squad.speed_ && experience_ == squad.experience_ &&
        team_ == squad.team_ && name_ == squad.name_ &&
        damage_ == squad.damage_ && shield_ == squad.shield_ &&
        type_ == squad.type_)
        return true;
    else
        return false;
}

bool Moral::operator!=(const Moral &squad) const {
    return !(*this == squad);
}

}  // namespace squad