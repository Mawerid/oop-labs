#ifndef CONFIG_TILES_HPP
#define CONFIG_TILES_HPP

#include "../include/landscape.hpp"

using namespace std;

static const map<field::Cell, pair<int, int>> tile_coords{
    {field::cell_type::OBSTAClE, make_pair(102, 51)},
    {field::cell_type::FREE, make_pair(17, 68)}};

static const map<game::player_type, pair<int, int>> player_tile_coords{
    {game::player_type::RIGHT, make_pair(119, 0)},
    {game::player_type::LEFT, make_pair(153, 51)}};

static const map<constant::unit, pair<int, int>> unit_tile_coords{
    {constant::unit::ROBOMECH, make_pair(170, 34)},
    {constant::unit::CENTRY, make_pair(153, 34)},
    {constant::unit::COLOSSUS, make_pair(153, 17)},
    {constant::unit::GHOST, make_pair(170, 17)},
    {constant::unit::INFESTOR, make_pair(170, 51)},
    {constant::unit::DISRUPTOR, make_pair(136, 68)},
    {constant::unit::ELF, make_pair(153, 68)},
    {constant::unit::GNOME, make_pair(119, 34)},//
    {constant::unit::DENDRIOD, make_pair(119, 68)},
    {constant::unit::MARINE, make_pair(136, 0)},
    {constant::unit::CYCLONE, make_pair(119, 51)},
    {constant::unit::REAPER, make_pair(136, 34)},
    {constant::unit::POLTERGEIST, make_pair(153, 0)},
    {constant::unit::TYPHON, make_pair(136, 51)},
    {constant::unit::MIMIC, make_pair(170, 0)}};

#endif