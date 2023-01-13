#include "../include/immortal.hpp"

namespace squad {

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

constant::unit Immortal_moral::convert_name(const immortal_moral_type &type)
    const {
    return static_cast<constant::unit>(type * 3 + 2);
}

Immortal_moral::Immortal_moral(
    const immortal_moral_type &type) : Moral(convert_name(type)), type_(type) {}

Immortal_moral::Immortal_moral(const immortal_moral_type &type,
                               const unsigned &damage,
                               const unsigned &shield,
                               const int &moral)
    : Moral(convert_name(type), moral, damage, shield),
      type_(type) {}

Immortal_moral::Immortal_moral(const immortal_moral_type &type,
                               const unsigned &damage,
                               const unsigned &shield,
                               const unsigned &restore,
                               const double &probability,
                               const int &moral)
    : Moral(convert_name(type), moral, damage, shield),
      Immortal(restore, probability),
      type_(type) {}

immortal_moral_type Immortal_moral::get_type() const { return type_; }

void Immortal_moral::set_type(const immortal_moral_type &type) { type_ = type; }

void Immortal_moral::heal() {
    std::srand(std::time(nullptr));
    double rand_check = (double)((std::rand() % 100) / 100);

    if (probability_ > rand_check)
        this->set_health((health_ + restore_));
}

constant::unit Immortal_amoral::convert_name(const immortal_amoral_type &type)
    const {
    return static_cast<constant::unit>(type * 3 + 2);
}

Immortal_amoral::Immortal_amoral(
    const immortal_amoral_type &type) : Amoral(convert_name(type)),
                                        type_(type) {}

Immortal_amoral::Immortal_amoral(const immortal_amoral_type &type,
                                 const unsigned &damage,
                                 const unsigned &shield)
    : Amoral(convert_name(type), damage, shield), type_(type) {}

Immortal_amoral::Immortal_amoral(const immortal_amoral_type &type,
                                 const unsigned &damage,
                                 const unsigned &shield,
                                 const unsigned &restore,
                                 const double &probability)
    : Amoral(convert_name(type), damage, shield),
      Immortal(restore, probability),
      type_(type) {}

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
}  // namespace squad