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
    class Landscape
    {
    private:
        std::map<constant::school_type, school::School> school_table;
        field::Node *map;
        std::list<squad::Squad> units_list;

    public:
        /// @brief 
        Landscape();

        /// @brief 
        /// @param root 
        Landscape(field::Node *root);

        /// @brief 
        /// @param new_table 
        void set_school_table(const std::map<constant::school_type, school::School> &new_table);

        /// @brief 
        /// @param root 
        void set_map(field::Node *root);

        /// @brief 
        /// @param new_list 
        void set_units_list(const std::list<squad::Squad> &new_list);

        /// @brief 
        /// @return 
        std::map<constant::school_type, school::School> get_school_table() const;

        /// @brief 
        /// @return 
        field::Node *get_map() const;

        /// @brief 
        /// @return 
        std::list<squad::Squad> get_units_list() const;

        /// @brief 
        /// @param cell_1 
        /// @param cell_2 
        void move_squad(field::Cell *cell_1, field::Cell *cell_2);

        /// @brief 
        /// @param cell 
        void set_squad(field::Cell *cell);

        /// @brief 
        void play_next();
    };
}

#endif