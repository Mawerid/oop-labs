#ifndef UNIT_HPP
#define UNIT_HPP

#include "squad.hpp"

namespace squad
{
    class unit : public squad
    {
    protected:
        unsigned damage;
        unsigned defense;

    public:
        unit();
        unit(const unsigned &, const unsigned &);

        virtual unsigned get_damage_val();
        virtual unsigned get_defense_val();

        virtual void set_damage_val(const unsigned &);
        virtual void set_defense_val(const unsigned &);

        virtual void hit(squad);
        virtual void defence(squad);
    };
}

#endif