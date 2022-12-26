#include "../include/common_units.hpp"

namespace squad
{
    Amoral::Amoral() { type = squad::amoral_type::CENTRY; }

    Amoral::Amoral(const amoral_type &new_type) { type = new_type; }

    Amoral::Amoral(const amoral_type &new_type, const unsigned &dmg, const unsigned &def)
    {
        type = new_type;
        damage = dmg;
        defense = def;
    }

    Amoral::~Amoral()
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
        unsigned dam = this->get_damage_val();
        dam *= quantity;
        squad->get_hit(dam);
    }

    void Amoral::defence(Squad *squad)
    {
        auto unit = squad->get_name();
        unsigned damage = 0;
        if (unit % 3 == 1 || unit == 2 || unit == 5)
            damage = static_cast<Amoral *>(squad)->get_damage_val();
        else if (unit % 3 == 0 || unit == 14 || unit == 11)
            damage = static_cast<Moral *>(squad)->get_damage_val();
        this->get_hit(damage);
    }

    Moral::Moral()
    {
        type = squad::moral_type::ROBOMECH;
        moral = 0;
    }

    Moral::Moral(const moral_type &new_type)
    {
        type = new_type;
        moral = 0;
    }

    Moral::Moral(const moral_type &new_type, const int &new_moral)
    {
        type = new_type;
        moral = new_moral;
    }

    Moral::Moral(const moral_type &new_type, const int &new_moral, const unsigned &dmg, const unsigned &def)
    {
        type = new_type;
        moral = new_moral;
        damage = dmg;
        defense = def;
    }

    Moral::~Moral()
    {
    }

    moral_type Moral::get_type() const { return type; }

    int Moral::get_moral_val() const { return moral; }

    void Moral::set_type(const moral_type &new_type) { type = new_type; }

    void Moral::set_moral_val(const int &new_moral) { moral = new_moral; }

    unsigned Moral::get_damage_val() const { return damage; }

    unsigned Moral::get_defense_val() const { return defense; }

    void Moral::set_damage_val(const unsigned &dam) { damage = dam; }

    void Moral::set_defense_val(const unsigned &def) { defense = def; }

    void Moral::hit(Squad *squad)
    {
        unsigned dam = this->get_damage_val();
        dam *= quantity;
        squad->get_hit(dam);
    }

    void Moral::defence(Squad *squad)
    {
        auto unit = squad->get_name();
        unsigned damage = 0;
        if (unit % 3 == 1 || unit == 2 || unit == 5)
            damage = static_cast<Amoral *>(squad)->get_damage_val();
        else if (unit % 3 == 0 || unit == 14 || unit == 11)
            damage = static_cast<Moral *>(squad)->get_damage_val();
        this->get_hit(damage);
    }

    void Moral::balance()
    {
        if (moral > 0)
            moral--;
        else if (moral < 0)
            moral++;
    }

    void Moral::mod_moral(const int &modif) { moral += modif; }
}