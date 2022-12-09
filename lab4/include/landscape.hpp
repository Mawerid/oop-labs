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
    /// @brief class of all map
    class Landscape
    {
    private:
        std::map<constant::school_type, school::School> school_table;
        field::Node *map;
        std::list<squad::Squad> units_list;

    public:
        /// @brief  empty constructor
        Landscape();

        /// @brief  cosntructor
        /// @param root filed
        Landscape(field::Node *root);

        /// @brief  setter of schools table
        /// @param new_table    new table of schools of player
        void set_school_table(const std::map<constant::school_type, school::School> &new_table);

        /// @brief  setter of field(map)
        /// @param root root of 2D tree
        void set_map(field::Node *root);

        /// @brief  setter of units list
        /// @param new_list new units list
        void set_units_list(const std::list<squad::Squad> &new_list);

        /// @brief  getter of school table
        /// @return school table
        std::map<constant::school_type, school::School> get_school_table() const;

        /// @brief  getter of field(map)
        /// @return root to field(map)
        field::Node *get_map() const;

        /// @brief  getter of units list
        /// @return units list
        std::list<squad::Squad> get_units_list() const;

        /// @brief  move squad from one cell to another
        /// @param cell_1   cell from
        /// @param cell_2   cell to
        void move_squad(field::Cell *cell_1, field::Cell *cell_2);

        /// @brief  set squad to cell
        /// @param cell cell to set
        /// @param squad    squad to set
        void set_squad(field::Cell *cell, squad::Squad *squad);

        /// @brief  function of playing each squad
        void play_next();
    };
}

#endif