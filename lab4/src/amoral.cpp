#include "../include/amoral.hpp"

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

    void Amoral::hit(Squad *squad) { squad->get_hit(damage); }

    void Amoral::defence(Squad *squad)
    {
        auto unit = squad->get_name();
        unsigned damage = 0;
        if (unit % 3 == 1 || unit == 2 || unit == 5)
            damage = dynamic_cast<Amoral *>(squad)->get_damage_val();
        else if (unit % 3 == 0 || unit == 14 || unit == 11)
            damage = dynamic_cast<Moral *>(squad)->get_damage_val();
        // else if (unit == 14 || unit == 11)
        //     damage = dynamic_cast<Immortal_moral *>(squad)->get_damage_val();
        // else if (unit == 2 || unit == 5)
        //     damage = dynamic_cast<Immortal_amoral *>(squad)->get_damage_val();

        this->get_hit(damage);
    }

    void Amoral::die()
    {
        return;
    }

}