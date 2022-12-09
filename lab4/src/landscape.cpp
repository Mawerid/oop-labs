#include "../include/landscape.hpp"
#include <stdexcept>


namespace game
{
    Landscape::Landscape()
    {
        school_table = {};
        map = nullptr;
        units_list = {};
    }

    Landscape::Landscape(field::Node *root)
    {
        school_table = {};
        map = root;
        units_list = {};
    }

    void Landscape::set_school_table(const std::map<constant::school_type, school::School> &new_table) { school_table = new_table; }

    void Landscape::set_map(field::Node *root) { map = root; }

    void Landscape::set_units_list(const std::list<squad::Squad> &new_list) { units_list = new_list; }

    std::map<constant::school_type, school::School> Landscape::get_school_table() const { return school_table; }

    field::Node *Landscape::get_map() const { return map; }

    std::list<squad::Squad> Landscape::get_units_list() const { return units_list; }

    void Landscape::move_squad(field::Cell *cell_1, field::Cell *cell_2)
    {
        auto *tmp = cell_1->get_filling();
        cell_1->set_filling(cell_2->get_filling());
        cell_2->set_filling(tmp);
    }

    void Landscape::set_squad(field::Cell *cell, squad::Squad *squad)
    {
        if (cell->get_type() != field::cell_type::FREE)
            throw std::invalid_argument("There is already a squad");
        cell->set_filling(squad);
    }

    void Landscape::play_next()
    {
        
    }
}