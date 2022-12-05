#include "../include/landscape.hpp"

namespace game
{
    Landscape::Landscape()
    {
    }

    Landscape::Landscape(field::Node *root)
    {
    }

    void Landscape::set_school_table(const std::map<constant::school_type, school::School> &new_table) { school_table = new_table; }

    void Landscape::set_map(field::Node *root) { map = root; }

    void Landscape::set_units_list(const std::list<squad::Squad> &new_list) { units_list = new_list; }

    std::map<constant::school_type, school::School> Landscape::get_school_table() const { return school_table; }

    field::Node *Landscape::get_map() const { return map; }

    std::list<squad::Squad> Landscape::get_units_list() const { return units_list; }

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