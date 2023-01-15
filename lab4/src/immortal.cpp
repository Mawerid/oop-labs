#include "../include/immortal.hpp"

namespace squad {

// Immortal

Immortal::Immortal() : restore_(10), probability_(0.5) {}

Immortal::Immortal(const unsigned &restore,
                   const double &probability) : restore_(restore),
                                                probability_(probability) {}

unsigned Immortal::get_restore() const { return restore_; }

double Immortal::get_probability() const { return probability_; }

void Immortal::set_restore(const unsigned &restore) { restore_ = restore; }

void Immortal::set_probability(const double &probability) {
    if (probability >= 0.0 && probability <= 1.0)
        probability_ = probability;
}

// Immortal Moral

immortal_moral_type convert_to_immortal_moral(const constant::unit &name) {
    switch (name) {
        case constant::unit::DENDRIOD:
            return immortal_moral_type::DENDRIOD;
            break;
        case constant::unit::REAPER:
            return immortal_moral_type::REAPER;
            break;
        case constant::unit::MIMIC:
            return immortal_moral_type::MIMIC;
            break;
        default:
            return immortal_moral_type::NONE;
            break;
    }
}

constant::unit Immortal_moral::convert_name(const immortal_moral_type &type)
    const {
    return static_cast<constant::unit>(type * 3 + 2);
}

Immortal_moral::Immortal_moral(
    const immortal_moral_type &type) : Moral(convert_name(type)), type_(type) {}

Immortal_moral::Immortal_moral(const immortal_moral_type &type,
                               const int &moral)
    : Moral(convert_name(type), moral),
      type_(type) {}

Immortal_moral::Immortal_moral(const immortal_moral_type &type,
                               const unsigned &restore,
                               const double &probability,
                               const int &moral)
    : Moral(convert_name(type), moral),
      Immortal(restore, probability),
      type_(type) {}

Immortal_moral::Immortal_moral(const Immortal_moral &squad)
    : Moral(convert_name(squad.type_)),
      Immortal(squad.restore_, squad.probability_),
      type_(squad.type_) {}

Immortal_moral::Immortal_moral(Immortal_moral &&squad)
    : Moral(convert_name(squad.type_)),
      Immortal(squad.restore_, squad.probability_),
      type_(squad.type_) {}

immortal_moral_type Immortal_moral::get_type() const { return type_; }

void Immortal_moral::set_type(const immortal_moral_type &type) { type_ = type; }

void Immortal_moral::heal() {
    std::srand(std::time(nullptr));
    double rand_check = (double)((std::rand() % 100) / 100);

    if (probability_ > rand_check)
        this->set_health((health_ + restore_));
}

bool Immortal_moral::operator==(const Immortal_moral &squad) const {
    if (motivation_ == squad.motivation_ && health_ == squad.health_ &&
        max_health_ == squad.max_health_ && quantity_ == squad.quantity_ &&
        speed_ == squad.speed_ && experience_ == squad.experience_ &&
        team_ == squad.team_ && name_ == squad.name_ &&
        damage_ == squad.damage_ && shield_ == squad.shield_ &&
        type_ == squad.type_ && restore_ == squad.restore_ &&
        probability_ == squad.probability_)
        return true;
    else
        return false;
}

bool Immortal_moral::operator!=(const Immortal_moral &squad) const {
    return !(*this == squad);
}

// Immortal Amoral

immortal_amoral_type convert_to_immortal_amoral(const constant::unit &name) {
    switch (name) {
        case constant::unit::COLOSSUS:
            return immortal_amoral_type::COLOSSUS;
            break;
        case constant::unit::DISRUPTOR:
            return immortal_amoral_type::DISRUPTOR;
            break;
        default:
            return immortal_amoral_type::NONE;
            break;
    }
}

constant::unit Immortal_amoral::convert_name(const immortal_amoral_type &type)
    const {
    return static_cast<constant::unit>(type * 3 + 2);
}

Immortal_amoral::Immortal_amoral(
    const immortal_amoral_type &type) : Amoral(convert_name(type)),
                                        type_(type) {}

Immortal_amoral::Immortal_amoral(const immortal_amoral_type &type,
                                 const unsigned &restore,
                                 const double &probability)
    : Amoral(convert_name(type)),
      Immortal(restore, probability),
      type_(type) {}

Immortal_amoral::Immortal_amoral(const Immortal_amoral &squad)
    : Amoral(convert_name(squad.type_)),
      Immortal(squad.restore_, squad.probability_),
      type_(squad.type_) {}

Immortal_amoral::Immortal_amoral(Immortal_amoral &&squad)
    : Amoral(convert_name(squad.type_)),
      Immortal(squad.restore_, squad.probability_),
      type_(squad.type_) {}

immortal_amoral_type Immortal_amoral::get_type() const { return type_; }

void Immortal_amoral::set_type(const immortal_amoral_type &type) {
    type_ = type;
}

void Immortal_amoral::heal() {
    std::srand(std::time(nullptr));
    double rand_check = (double)((std::rand() % 100) / 100);

    if (probability_ > rand_check)
        this->set_health((health_ + restore_));
}

bool Immortal_amoral::operator==(const Immortal_amoral &squad) const {
    if (motivation_ == squad.motivation_ && health_ == squad.health_ &&
        max_health_ == squad.max_health_ && quantity_ == squad.quantity_ &&
        speed_ == squad.speed_ && experience_ == squad.experience_ &&
        team_ == squad.team_ && name_ == squad.name_ &&
        damage_ == squad.damage_ && shield_ == squad.shield_ &&
        type_ == squad.type_ && restore_ == squad.restore_ &&
        probability_ == squad.probability_)
        return true;
    else
        return false;
}

bool Immortal_amoral::operator!=(const Immortal_amoral &squad) const {
    return !(*this == squad);
}

}  // namespace squad