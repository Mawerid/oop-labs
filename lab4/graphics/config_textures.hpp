#ifndef CONFIG_TILES_HPP
#define CONFIG_TILES_HPP

#include <SFML/Graphics.hpp>

#include "../include/landscape.hpp"

namespace game {

static const std::map<player_type, sf::Color> colors{
    {player_type::RIGHT, sf::Color::Red},
    {player_type::LEFT, sf::Color::Blue}};

static const std::map<field::cell_type, std::pair<int, int>>
    field_coords{
        {field::cell_type::OBSTAClE, std::make_pair(96, 48)},
        {field::cell_type::BUSY, std::make_pair(16, 64)},
        {field::cell_type::FREE, std::make_pair(16, 64)}};

static const std::map<player_type, std::pair<int, int>>
    players_coords{
        {player_type::LEFT, std::make_pair(112, 0)},
        {player_type::RIGHT, std::make_pair(144, 48)}};

static const std::map<constant::unit, std::pair<int, int>>
    units_coords{
        {constant::unit::ROBOMECH, std::make_pair(160, 32)},
        {constant::unit::CENTRY, std::make_pair(144, 32)},
        {constant::unit::COLOSSUS, std::make_pair(144, 16)},
        {constant::unit::GHOST, std::make_pair(160, 16)},
        {constant::unit::INFESTOR, std::make_pair(160, 48)},
        {constant::unit::DISRUPTOR, std::make_pair(128, 64)},
        {constant::unit::ELF, std::make_pair(144, 64)},
        {constant::unit::GNOME, std::make_pair(112, 32)},
        {constant::unit::DENDRIOD, std::make_pair(112, 64)},
        {constant::unit::MARINE, std::make_pair(128, 0)},
        {constant::unit::CYCLONE, std::make_pair(112, 48)},
        {constant::unit::REAPER, std::make_pair(128, 32)},
        {constant::unit::POLTERGEIST, std::make_pair(144, 0)},
        {constant::unit::TYPHON, std::make_pair(128, 48)},
        {constant::unit::MIMIC, std::make_pair(160, 0)}};
}  // namespace game

#endif