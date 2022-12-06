#include "../include/moral.hpp"

namespace squad
{
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

    void Moral::hit(Squad *squad) { squad->get_hit(damage); }

    void Moral::defence(Squad *squad)
    {

        // this->get_hit(squad.get_damage())
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