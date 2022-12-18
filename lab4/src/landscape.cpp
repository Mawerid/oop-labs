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

    Landscape::Landscape(std::KDTree<field::Cell, std::vector<field::Cell>> *root)
    {
        school_table = {};
        map = root;
        units_list = {};
    }

    void Landscape::set_school_table(const std::map<constant::school_type, school::School> &new_table) { school_table = new_table; }

    void Landscape::set_map(std::KDTree<field::Cell, std::vector<field::Cell>> *root) { map = root; }

    void Landscape::set_units_list(const std::list<squad::Squad *> &new_list) { units_list = new_list; }

    std::map<constant::school_type, school::School> Landscape::get_school_table() const { return school_table; }

    std::KDTree<field::Cell, std::vector<field::Cell>> *Landscape::get_map() const { return map; }

    std::list<squad::Squad *> Landscape::get_units_list() const { return units_list; }

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
        squad::Squad *squad = units_list.front();
        units_list.pop_front();

        auto unit = squad->get_name();
        if (unit % 3 == 1 || unit == 2 || unit == 5)
            squad = dynamic_cast<squad::Amoral *>(squad);
        else if (unit % 3 == 0 || unit == 14 || unit == 11)
            squad = dynamic_cast<squad::Moral *>(squad);
        else if (unit == 14 || unit == 11)
            squad = dynamic_cast<squad::Immortal_moral *>(squad);
        else if (unit == 2 || unit == 5)
            squad = dynamic_cast<squad::Immortal_amoral *>(squad);
        else
            squad = dynamic_cast<squad::Lord *>(squad);

        char what_to_do;
        std::cin >> what_to_do;

        switch (what_to_do)
        {
        case 'h':
            // squad->get_hit(map->getPointsWithinCube(map->getPoint(squad->get_speed()), 1));
            break;
        case 'm':
            // move_squad()
            break;
        case 'u':
            // squad.upgrade_school();
            break;
        case 'p':
            // squad.call_squad();
        default:
            break;
        }

        if (squad)
            units_list.push_back(squad);
    }
}