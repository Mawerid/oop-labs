#include "../include/common_units.hpp"

namespace squad {

constant::unit Amoral::convert_name(const amoral_type &type) const {
    return static_cast<constant::unit>(type * 3 + 1);
}

Amoral::Amoral(const amoral_type &type) : Unit(convert_name(type)), type_(type) {}

Amoral::Amoral(const amoral_type &type, const unsigned &damage,
               const unsigned &shield) : Unit(convert_name(type),
                                              damage, shield),
                                         type_(type) {}

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

constant::unit Moral::convert_name(const moral_type &type) const {
    return static_cast<constant::unit>(type * 3);
}

Moral::Moral(const moral_type &type) : Unit(convert_name(type)),
                                       type_(type),
                                       moral_(0) {}

Moral::Moral(const moral_type &type,
             const int &moral) : Unit(convert_name(type)),
                                 type_(type),
                                 moral_(moral) {}

Moral::Moral(const moral_type &type, const int &moral,
             const unsigned &damage,
             const unsigned &shield) : Unit(convert_name(type),
                                            damage, shield),
                                       type_(type),
                                       moral_(moral) {}

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
    unsigned damage = (-1) * moral_;
    if (unit % 3 == 1 || unit == 2 || unit == 5)
        damage += static_cast<Amoral &>(squad).get_damage_val();
    else if (unit % 3 == 0 || unit == 14 || unit == 11)
        damage += static_cast<Moral &>(squad).get_damage_val();
    this->get_damage(damage);
}

void Moral::balance_moral() {
    if (moral_ > 0)
        moral_--;
    else if (moral_ < 0)
        moral_++;
}

void Moral::modify_moral(const int &modify) { moral_ += modify; }
}  // namespace squad