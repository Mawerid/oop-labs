#include "../include/amoral.hpp"

namespace squad
{
    Amoral::Amoral()
    {
    }

    Amoral::Amoral(const amoral_type &new_type)
    {
    }

    Amoral::Amoral(const amoral_type &new_type, const unsigned &damage, const unsigned &defense)
    {
    }

    amoral_type Amoral::get_type() const { return type; }

    void Amoral::set_type(const amoral_type &new_type) { type = new_type; }

    unsigned Amoral::get_damage_val() const { return damage; }

    unsigned Amoral::get_defense_val() const { return defense; }

    void Amoral::set_damage_val(const unsigned &dam) { damage = dam; }

    void Amoral::set_defense_val(const unsigned &def) { defense = def; }

    void Amoral::hit(Squad *squad)
    {
    }

    void Amoral::defence(Squad *squad)
    {
    }
}