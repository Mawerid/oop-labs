#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "constants.hpp"

namespace squad
{
    class squad
    {
    protected:
        unsigned motivation;
        unsigned health;
        unsigned max_health;
        size_t quantity;
        unsigned speed;
        unsigned experience;
        unsigned team;
        constant::unit name;

    public:
        squad();
        squad(const size_t, const unsigned &, const unsigned &);
        squad(const constant::unit &);
        squad(const unsigned &, const unsigned &, const unsigned &, const unsigned &);
        squad(const squad &);

        void set_motivation(const unsigned &);
        void set_health(const unsigned &);
        void set_max_health(const unsigned &);
        void set_speed(const unsigned &);
        void set_experience(const unsigned &);
        void set_team(const unsigned &);
        void set_quantity(const size_t &);
        void set_name(const constant::unit &);

        unsigned get_motivation();
        unsigned get_health();
        unsigned get_max_health();
        unsigned get_speed();
        unsigned get_experience();
        unsigned get_team();
        size_t get_quantity();
        constant::unit get_name();

        void get_type();
        void get_hit(unsigned);
        void die();
    };
}

#endif