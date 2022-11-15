#ifndef MORAL_HPP
#define MORAL_HPP

#include "unit.hpp"

namespace squad
{
    enum class moral_type
    {
        ROBOMECH,
        GHOST,
        ELF,
        MARINE,
        POLTERGEIST
    };

    class moral : public unit
    {
    protected:
        moral_type type;
        int moral;

    public:
        moral();
        moral(const moral_type &);
        moral(const moral_type &, const int &);

        moral_type get_type();
        int get_moral_val();

        void set_type(const moral_type &);
        void set_moral_val(const int &);

        void hit(squad);
        void balance();
        void mod_moral(const int &);
    };
}

#endif