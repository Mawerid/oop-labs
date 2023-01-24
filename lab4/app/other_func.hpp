#include <iostream>

#include "../graphics/set_tiles.hpp"

namespace game {

template <class T>
int get_num(T &a) {
    std::cin >> a;
    if (!std::cin.good()) {
        std::cin.clear();
        while (std::cin.get() != '\n')
            continue;
        return 1;
    }
    return 0;
}

static const sf::Vector2i tile_size(16, 16);
static const float scale = 4.f;

static const float height = MAP_SIZE_HORIZONTAL * tile_size.x * scale;
static const float width = MAP_SIZE_VERTICAL * tile_size.y * scale;

static const char font_path[] =
    "../fonts_tilesets/FROGBLOCK-V2.1-by-Polyducks.ttf";
static const char texture_path[] = "../fonts_tilesets/tilemap_packed.png";
static const char game_name[] = "The Call of the Wild";

static const std::map<constant::unit, std::string> name_to_str{
    {constant::unit::ROBOMECH, "Robomech"},
    {constant::unit::CENTRY, "Centry"},
    {constant::unit::COLOSSUS, "Colossus"},
    {constant::unit::GHOST, "Ghost"},
    {constant::unit::INFESTOR, "Infestor"},
    {constant::unit::DISRUPTOR, "Disruptor"},
    {constant::unit::ELF, "Elf"},
    {constant::unit::GNOME, "Gnome"},
    {constant::unit::DENDROID, "Dendroid"},
    {constant::unit::MARINE, "Marine"},
    {constant::unit::CYCLONE, "Cyclone"},
    {constant::unit::REAPER, "Reaper"},
    {constant::unit::POLTERGEIST, "Poltergeist"},
    {constant::unit::TYPHON, "Typhon"},
    {constant::unit::MIMIC, "Mimic"},
    {constant::unit::LORD, "Lord"},
};

void render(sf::RenderWindow &window, sf::Texture &texture,
            sf::Text &text, game::Landscape &game, std::pair<int, int> current);

void preview(sf::RenderWindow &window, sf::Text &text);

void show_menu(sf::RenderWindow &window, sf::Text &text);

void show_school_tables(sf::RenderWindow &window, sf::Text &text,
                        game::Landscape &game);

void show_units(sf::RenderWindow &window, sf::Text &text);

std::pair<unsigned, unsigned> move_current(
    std::pair<unsigned, unsigned> &current,
    int diff_vertical,
    int diff_horizontal,
    squad::Squad *unit,
    field::Point current_position);

void show_queue(sf::RenderWindow &window, sf::Text &text,
                Landscape::queue queue);

void show_skills(sf::RenderWindow &window, sf::Text &text,
                 constant::unit name);

bool check_end(Landscape &game);

void show_end(sf::RenderWindow &window, sf::Text &text, player_type type);

unsigned get_school();

unsigned get_unit();

}  // namespace game