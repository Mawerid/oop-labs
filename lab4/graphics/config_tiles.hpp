#ifndef CONFIG_TILES_HPP
#define CONFIG_TILES_HPP

#include <SFML/Graphics.hpp>
#include "../include/landscape.hpp"


namespace game
{

    static const std::map<field::Cell, std::pair<int, int>> tile_coords{
        {field::cell_type::OBSTAClE, std::make_pair(102, 51)},
        {field::cell_type::FREE, std::make_pair(17, 68)}};

    static const std::map<game::player_type, std::pair<int, int>> player_tile_coords{
        {game::player_type::RIGHT, std::make_pair(119, 0)},
        {game::player_type::LEFT, std::make_pair(153, 51)}};

    static const std::map<constant::unit, std::pair<int, int>> unit_tile_coords{
        {constant::unit::ROBOMECH, std::make_pair(170, 34)},
        {constant::unit::CENTRY, std::make_pair(153, 34)},
        {constant::unit::COLOSSUS, std::make_pair(153, 17)},
        {constant::unit::GHOST, std::make_pair(170, 17)},
        {constant::unit::INFESTOR, std::make_pair(170, 51)},
        {constant::unit::DISRUPTOR, std::make_pair(136, 68)},
        {constant::unit::ELF, std::make_pair(153, 68)},
        {constant::unit::GNOME, std::make_pair(119, 34)}, //
        {constant::unit::DENDRIOD, std::make_pair(119, 68)},
        {constant::unit::MARINE, std::make_pair(136, 0)},
        {constant::unit::CYCLONE, std::make_pair(119, 51)},
        {constant::unit::REAPER, std::make_pair(136, 34)},
        {constant::unit::POLTERGEIST, std::make_pair(153, 0)},
        {constant::unit::TYPHON, std::make_pair(136, 51)},
        {constant::unit::MIMIC, std::make_pair(170, 0)}};
}

#endif