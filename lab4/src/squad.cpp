#include "../include/squad.hpp"

namespace squad
{
    Squad::Squad()
    {
        motivation = 0;
        health = 1;
        max_health = 1;
        quantity = 1;
        speed = 0;
        experience = 0;
        team = 1;
        name = constant::unit::LORD;
    }

    Squad::Squad(const size_t &quant, const unsigned &max_heal, const unsigned &new_team, const constant::unit &new_name)
    {
        motivation = 0;
        health = 1;
        max_health = max_heal;
        quantity = quant;
        speed = 0;
        experience = 0;
        team = new_team;
        name = new_name;
    }

    Squad::Squad(const constant::unit &new_name)
    {
        motivation = 0;
        health = 1;
        max_health = 0;
        quantity = 0;
        speed = 0;
        experience = 0;
        team = 0;
        name = new_name;
    }

    Squad::Squad(const unsigned &motiv, const unsigned &heal, const unsigned &max_heal, const size_t quant, const unsigned &spd, const unsigned &exp, const unsigned &new_team, const constant::unit &new_name)
    {
        motivation = motiv;
        health = heal;
        max_health = max_heal;
        quantity = quant;
        speed = spd;
        experience = exp;
        team = new_team;
        name = new_name;
    }

    Squad::Squad(const Squad &squad)
    {
        motivation = squad.motivation;
        health = squad.health;
        max_health = squad.max_health;
        quantity = squad.quantity;
        speed = squad.speed;
        experience = squad.experience;
        team = squad.team;
        name = squad.name;
    }

    Squad::Squad(Squad &&squad)
    {
        motivation = squad.motivation;
        health = squad.health;
        max_health = squad.max_health;
        quantity = squad.quantity;
        speed = squad.speed;
        experience = squad.experience;
        team = squad.team;
        name = squad.name;
    }

    Squad::~Squad() {}

    void Squad::set_motivation(const unsigned &motiv) { motivation = motiv; }

    void Squad::set_health(const unsigned &heal)
    {
        if (heal <= max_health)
            health = heal;
        else
            health = max_health;
    }

    void Squad::set_max_health(const unsigned &max_heal) { max_health = max_heal; }

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

    // void get_type();

    void Squad::get_hit(unsigned &damage)
    {
        if (health < damage)
        {
            health = 0;
            die();
        }
        else
            health -= damage;
    }

    void Squad::die() {}

    Squad Squad::operator=(const Squad &squad)
    {
        motivation = squad.motivation;
        health = squad.health;
        max_health = squad.max_health;
        quantity = squad.quantity;
        speed = squad.speed;
        experience = squad.experience;
        team = squad.team;
        name = squad.name;

        return *this;
    }
}