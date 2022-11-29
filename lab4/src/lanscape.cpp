#include "../include/landscape.hpp"

namespace game
{
    Landscape::Landscape()
    {
    }

    Landscape::Landscape(field::Node *root)
    {
    }

    void Landscape::set_school_table(const std::map<constant::school_type, school::School> &new_table)
    {
    }

    void Landscape::set_map(field::Node *root)
    {
    }

    void Landscape::set_units_list(const std::list<squad::Squad> &new_list)
    {
    }

    std::map<constant::school_type, school::School> Landscape::get_school_table() const
    {
    }

    field::Node *Landscape::get_map() const
    {
    }

    std::list<squad::Squad> Landscape::get_units_list() const
    {
    }

    void Landscape::move_squad(field::Cell *cell_1, field::Cell *cell_2)
    {
    }

    void Landscape::set_squad(field::Cell *cell)
    {
    }

    void Landscape::play_next()
    {
    }
}