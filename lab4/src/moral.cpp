#include "../include/moral.hpp"

namespace squad
{
    Moral::Moral()
    {
    }

    Moral::Moral(const moral_type &new_type)
    {
    }

    Moral::Moral(const moral_type &new_type, const int &new_moral)
    {
    }

    Moral::Moral(const moral_type &new_type, const int &new_moral, const unsigned &damage, const unsigned &defense)
    {
    }

    moral_type Moral::get_type() const { return type; }

    int Moral::get_moral_val() const { return moral; }

    void Moral::set_type(const moral_type &new_type)
    {
    }

    void Moral::set_moral_val(const int &new_moral)
    {
    }

    unsigned Moral::get_damage_val() const { return damage; }

    unsigned Moral::get_defense_val() const { return defense; }

    void Moral::set_damage_val(const unsigned &dam)
    {
    }

    void Moral::set_defense_val(const unsigned &def)
    {
    }

    void Moral::hit(Squad *squad)
    {
    }

    void Moral::defence(Squad *squad)
    {
    }

    void Moral::balance()
    {
    }

    void Moral::mod_moral(const int &modif)
    {
    }
}