#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <map>
#include <list>
#include <string>
#include <vector>
#include "cell.hpp"

namespace game
{
    enum player_type
    {
        RIGHT,
        LEFT
    };

    /// @brief class of all map
    class Landscape
    {
    public:
        typedef std::map<constant::school_type, school::School> school_table_type;
        typedef std::vector<std::vector<field::Cell>> map_type;
        typedef std::list<squad::Squad *> list;
        typedef std::pair<size_t, size_t> size_type;

    private:
        school_table_type school_table;
        map_type map;
        list units_list;

    public:
        const size_type size = {10, 15};

        /// @brief  empty constructor
        Landscape();

        /// @brief  cosntructor
        /// @param root filed
        Landscape(const map_type &root);

        /// @brief  setter of schools table
        /// @param new_table    new table of schools of player
        void set_school_table(const school_table_type &new_table);

        /// @brief  setter of field(map)
        /// @param root root of 2D tree
        void set_map(const map_type &map);

        /// @brief  setter of units list
        /// @param new_list new units list
        void set_units_list(const list &new_list);

        /// @brief  getter of school table
        /// @return school table
        school_table_type get_school_table() const;

        /// @brief  getter of field(map)
        /// @return root to field(map)
        map_type get_map() const;

        /// @brief  getter of units list
        /// @return units list
        list get_units_list() const;

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

        /// @brief
        void init();
    };
}

#endif