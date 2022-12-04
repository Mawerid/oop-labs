#include "../include/immortal_moral.hpp"

namespace squad
{
    Immortal_moral::Immortal_moral()
    {
        type = immortal_moral_type::REAPER;
    }

    Immortal_moral::Immortal_moral(const immortal_moral_type &new_type)
    {
        type = new_type;
    }

    immortal_moral_type Immortal_moral::get_type() { return type; }

    void Immortal_moral::set_type(const immortal_moral_type &new_type) { type = new_type; }
}