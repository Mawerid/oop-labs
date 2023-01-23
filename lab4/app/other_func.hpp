#include "../graphics/set_tiles.hpp"

namespace game {

static const sf::Vector2i tile_size(16, 16);
static const float scale = 4.f;

static const float height = MAP_SIZE_HORIZONTAL * tile_size.x * scale;
static const float width = MAP_SIZE_VERTICAL * tile_size.y * scale;

static const char font_path[] =
    "../fonts_tilesets/FROGBLOCK-V2.1-by-Polyducks.ttf";
static const char texture_path[] = "../fonts_tilesets/tilemap_packed.png";
static const char game_name[] = "The Call of the Wild";

void render(sf::RenderWindow &window, sf::Texture &texture,
            sf::Text &text, game::Landscape &game);

void preview(sf::RenderWindow &window, sf::Text &text);

void show_menu(sf::RenderWindow &window, sf::Text &text);

void show_school_tables(sf::RenderWindow &window, sf::Text &text,
                        game::Landscape &game);

void show_units(sf::RenderWindow &window, sf::Text &text);
}