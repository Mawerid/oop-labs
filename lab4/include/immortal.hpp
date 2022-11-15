#ifndef IMMORTAL_HPP
#define IMMORTAL_HPP

#include "common.hpp"

namespace squad
{
    enum immortal_type
    {
        COLOSSUS,
        DISRUPTOR,
        DENDTIOD,
        REAPER,
        MIMIC
    };

    class immortal : public amoral, public common
    {
    private:
        immortal_type type;
        unsigned restore;
        double probability;

    public:
        immortal();
        immortal(const immortal_type &);
        immortal(const immortal_type &, const unsigned &);
        immortal(const immortal_type &, const double &);
        immortal(const immortal_type &, const unsigned &, const double &);

        immortal_type get_type();
        unsigned get_restore();
        double get_probability();

        void set_type(const immortal_type &);
        void set_restore(const unsigned &);
        void set_probability(const double &);

        void heal();
    };
}

#endif