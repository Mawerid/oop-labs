#include "../include/squad.hpp"

#include <string>

namespace squad {

Squad::Squad(const constant::unit &new_name) : speed(constant::speed[new_name]),
                                               motivation(constant::motivation[new_name]),
                                               health(constant::max_health[new_name]),
                                               max_health(constant::max_health[new_name]),
                                               quantity(constant::max_quantity[new_name]),
                                               experience(constant::experience[new_name]),
                                               team(0),
                                               name(new_name) {}

Squad::Squad(const constant::unit &new_name,
             const unsigned &new_team) : speed(constant::speed[new_name]),
                                         motivation(constant::motivation[new_name]),
                                         health(constant::max_health[new_name]),
                                         max_health(constant::max_health[new_name]),
                                         quantity(constant::max_quantity[new_name]),
                                         experience(constant::experience[new_name]),
                                         team(0),
                                         name(new_name) {}

Squad::Squad(const unsigned &motiv, const unsigned &heal,
             const unsigned &max_heal, const size_t quant,
             const unsigned &spd, const unsigned &exp,
             const unsigned &new_team, const constant::unit &new_name) : motivation(motiv), health(heal), max_health(max_heal), quantity(quant), speed(spd), experience(exp), team(new_team), name(new_name) {}

Squad::Squad(const Squad &squad) : motivation(squad.motivation),
                                   health(squad.health),
                                   max_health(squad.max_health),
                                   quantity(squad.quantity),
                                   speed(squad.speed),
                                   experience(squad.experience),
                                   team(squad.team),
                                   name(squad.name) {}

Squad::Squad(Squad &&squad) : motivation(squad.motivation),
                              health(squad.health),
                              max_health(squad.max_health),
                              quantity(squad.quantity),
                              speed(squad.speed),
                              experience(squad.experience),
                              team(squad.team),
                              name(squad.name) {}

Squad::~Squad() {}

void Squad::set_health(const unsigned &heal) {
    if (heal <= max_health)
        health = heal;
    else
        health = max_health;
}

void Squad::set_max_health(const unsigned &max_heal) {
    max_health = max_heal;
    health = max_heal;
}

void Squad::set_motivation(const unsigned &motiv) { motivation = motiv; }
void Squad::set_speed(const unsigned &spd) { speed = spd; }
void Squad::set_experience(const unsigned &exp) { experience = exp; }
void Squad::set_team(const unsigned &new_team) { team = new_team; }
void Squad::set_quantity(const size_t &quant) { quantity = quant; }
void Squad::set_name(const constant::unit &new_name) { name = new_name; }

unsigned Squad::get_motivation() const { return motivation; }
unsigned Squad::get_health() const { return health; }
unsigned Squad::get_max_health() const { return max_health; }
unsigned Squad::get_speed() const { return speed; }
unsigned Squad::get_experience() const { return experience; }
unsigned Squad::get_team() const { return team; }
size_t Squad::get_quantity() const { return quantity; }
constant::unit Squad::get_name() const { return name; }

void Squad::get_damage(const unsigned &damage) {
    if (health < damage)
        health = 0;
    else
        health -= damage;
}

Squad &Squad::operator=(const Squad &squad) {
    if (this != &squad) {
        motivation = squad.motivation;
        health = squad.health;
        max_health = squad.max_health;
        quantity = squad.quantity;
        speed = squad.speed;
        experience = squad.experience;
        team = squad.team;
        name = squad.name;
    }
    return *this;
}

Squad &Squad::operator=(Squad &&squad) {
    size_t tmp;
    std::swap(squad.experience, experience);
    std::swap(squad.motivation, motivation);
    std::swap(squad.health, health);
    std::swap(squad.max_health, max_health);
    std::swap(squad.quantity, quantity);
    std::swap(squad.speed, speed);
    std::swap(squad.team, team);
    std::swap(squad.name, name);

    return *this;
}

bool Squad::operator==(const Squad &squad) {
    if (motivation == squad.motivation && health == squad.health &&
        max_health == squad.max_health && quantity == squad.quantity &&
        speed == squad.speed && experience == squad.experience &&
        team == squad.team && name == squad.name)
        return true;
    else
        return false;
}

bool Squad::operator!=(const Squad &squad) {
    return !(*this == squad);
}
}  // namespace squad