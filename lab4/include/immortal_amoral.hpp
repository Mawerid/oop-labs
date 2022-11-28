#ifndef IMMORTAL_AMORAL_HPP
#define IMMORTAL_AMORAL_HPP

#include "amoral.hpp"
#include "immortal.hpp"

namespace squad
{
    enum class immortal_amoral_type
    {
        COLOSSUS,
        DISRUPTOR,
        MIMIC
    };

    class immortal_amoral : public amoral, public immortal
    {
    private:
        immortal_amoral_type type;

    public:
        immortal_amoral();
        immortal_amoral(const immortal_amoral_type &);

        immortal_amoral_type get_type();

        void set_type(const immortal_amoral_type &);
    };
}

#endif