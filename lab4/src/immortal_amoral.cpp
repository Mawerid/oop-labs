#include "../include/immortal_amoral.hpp"

namespace squad
{
    Immortal_amoral::Immortal_amoral()
    {
        type = immortal_amoral_type::COLOSSUS;
    }

    Immortal_amoral::Immortal_amoral(const immortal_amoral_type &new_type)
    {
        type = new_type;
    }

    immortal_amoral_type Immortal_amoral::get_type() { return type; }

    void Immortal_amoral::set_type(const immortal_amoral_type &new_type) { type = new_type; }
}