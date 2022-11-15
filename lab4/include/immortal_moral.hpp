#ifndef IMMORTAL_MORAL_HPP
#define IMMORTAL_MORAL_HPP

#include "moral.hpp"
#include "immortal.hpp"

namespace squad
{
    enum class immortal_moral_type
    {
        REAPER,
        MIMIC
    };

    class immortal_moral : public moral, public immortal
    {
    private:
        immortal_moral_type type;

    public:
        immortal_moral();
        immortal_moral(const immortal_moral_type &);

        immortal_moral_type get_type();

        void set_type(const immortal_moral_type &);
    };
}

#endif