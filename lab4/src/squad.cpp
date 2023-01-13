#include "../include/squad.hpp"

#include <string>

namespace squad {

Squad::Squad(const constant::unit &name) : speed_(constant::speed[name]),
                                           motivation_(constant::motivation[name]),
                                           health_(constant::max_health[name]),
                                           max_health_(constant::max_health[name]),
                                           quantity_(constant::max_quantity[name]),
                                           experience_(constant::experience[name]),
                                           team_(0),
                                           name_(name) {}

Squad::Squad(const constant::unit &name,
             const unsigned &team) : speed_(constant::speed[name]),
                                     motivation_(constant::motivation[name]),
                                     health_(constant::max_health[name]),
                                     max_health_(constant::max_health[name]),
                                     quantity_(constant::max_quantity[name]),
                                     experience_(constant::experience[name]),
                                     team_(team),
                                     name_(name) {}

Squad::Squad(const unsigned &motivation, const unsigned &health,
             const unsigned &max_health, const size_t quantity,
             const unsigned &speed, const unsigned &experience,
             const unsigned &team,
             const constant::unit &name) : motivation_(motivation),
                                           health_(health),
                                           max_health_(max_health),
                                           quantity_(quantity),
                                           speed_(speed),
                                           experience_(experience),
                                           team_(team),
                                           name_(name) {}

Squad::Squad(const Squad &squad) : motivation_(squad.motivation_),
                                   health_(squad.health_),
                                   max_health_(squad.max_health_),
                                   quantity_(squad.quantity_),
                                   speed_(squad.speed_),
                                   experience_(squad.experience_),
                                   team_(squad.team_),
                                   name_(squad.name_) {}

Squad::Squad(Squad &&squad) : motivation_(squad.motivation_),
                              health_(squad.health_),
                              max_health_(squad.max_health_),
                              quantity_(squad.quantity_),
                              speed_(squad.speed_),
                              experience_(squad.experience_),
                              team_(squad.team_),
                              name_(squad.name_) {}

void Squad::set_health(const unsigned &health) {
    if (health <= max_health_)
        health_ = health;
    else
        health_ = max_health_;
}

void Squad::set_max_health(const unsigned &max_health) {
    max_health_ = max_health;
    health_ = max_health;
}

void Squad::set_motivation(const unsigned &motivation) {
    motivation_ = motivation;
}
void Squad::set_speed(const unsigned &speed) { speed_ = speed; }
void Squad::set_experience(const unsigned &experience) {
    experience_ = experience;
}
void Squad::set_team(const unsigned &team) { team_ = team; }
void Squad::set_quantity(const size_t &quantity) { quantity_ = quantity; }
void Squad::set_name(const constant::unit &name) { name_ = name; }

unsigned Squad::get_motivation() const { return motivation_; }
unsigned Squad::get_health() const { return health_; }
unsigned Squad::get_max_health() const { return max_health_; }
unsigned Squad::get_speed() const { return speed_; }
unsigned Squad::get_experience() const { return experience_; }
unsigned Squad::get_team() const { return team_; }
size_t Squad::get_quantity() const { return quantity_; }
constant::unit Squad::get_name() const { return name_; }

void Squad::get_damage(const unsigned &damage) {
    if (health_ < damage)
        health_ = 0;
    else
        health_ -= damage;
}

Squad &Squad::operator=(const Squad &squad) {
    if (this != &squad) {
        motivation_ = squad.motivation_;
        health_ = squad.health_;
        max_health_ = squad.max_health_;
        quantity_ = squad.quantity_;
        speed_ = squad.speed_;
        experience_ = squad.experience_;
        team_ = squad.team_;
        name_ = squad.name_;
    }
    return *this;
}

Squad &Squad::operator=(Squad &&squad) {
    size_t tmp;
    std::swap(squad.experience_, experience_);
    std::swap(squad.motivation_, motivation_);
    std::swap(squad.health_, health_);
    std::swap(squad.max_health_, max_health_);
    std::swap(squad.quantity_, quantity_);
    std::swap(squad.speed_, speed_);
    std::swap(squad.team_, team_);
    std::swap(squad.name_, name_);

    return *this;
}

bool Squad::operator==(const Squad &squad) {
    if (motivation_ == squad.motivation_ && health_ == squad.health_ &&
        max_health_ == squad.max_health_ && quantity_ == squad.quantity_ &&
        speed_ == squad.speed_ && experience_ == squad.experience_ &&
        team_ == squad.team_ && name_ == squad.name_)
        return true;
    else
        return false;
}

bool Squad::operator!=(const Squad &squad) {
    return !(*this == squad);
}
}  // namespace squad