#ifndef COMMON_HPP
#define COMMON_HPP

#include "amoral.hpp"

namespace squad
{
    enum common_type
    {
        ROBOMECH,
        GHOST,
        ELF,
        MARINE,
        POLTERGEIST
    };

    class common : virtual public amoral
    {
    protected:
        common_type type;
        int moral;

    public:
        common();
        common(const common_type &);
        common(const common_type &, const int &);

        common_type get_type();
        int get_moral_val();

        void set_type(const common_type &);
        void set_moral_val(const int &);

        void hit(squad);
        void balance();
    };
}

#endif