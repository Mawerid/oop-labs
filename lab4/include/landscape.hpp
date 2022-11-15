#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <map>
#include <list>
#include <string>
#include "squad.hpp"
#include "field.hpp"
#include "school.hpp"
#include "constants.hpp"

namespace game
{
    class landscape
    {
    private:
        std::map<constant::school_type, school::school> school_table;
        field::node *map;
        std::list<squad::squad> units_list;

    public:
        landscape();
        landscape(field::node *);

        void set_school_table(const std::map<constant::school_type, school::school> &);
        void set_map(field::node *);
        void set_units_list(const std::list<squad::squad> &);

        std::map<constant::school_type, school::school> get_school_table();
        field::node *get_map();
        std::list<squad::squad> get_units_list();

        void move_squad(field::cell *, field::cell *);
        void set_squad(field::cell *);
        void play_next();
    };
}

#endif