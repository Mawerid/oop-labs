#include "set_tiles.hpp"
#include "config_tiles.hpp"

using namespace std;

TileMap::TileMap(const sf::Texture &texture, const sf::Text &text, const sf::Vector2i &tileSize, float scale)
    : m_texture(texture), m_text(text), m_tileSize(tileSize), m_scale(scale) {}

void TileMap::load(game::Landscape land)
{
    game::Landscape::map_type map = land.get_map();
    game::Landscape::list unit_list = land.get_units_list();
    game::Landscape::school_table_type table = land.get_school_table();

    const int height = land.size.first;
    const int width = land.size.second;

    m_vertices.resize(width * height * 4);

    for (int x = 0; x < height; ++x)
    {
        for (int y = 0; y < width; ++y)
        {
            const field::Cell tile = map[x][y];
            const pair<int, int> coords = tile_coords.at(tile);
            const float tu = coords.first, tv = coords.second;

            sf::Vertex *quad = &m_vertices[(y + x * width) * 4];

            quad[0].position = sf::Vector2f((y + 0.f) * m_tileSize.x * m_scale, (x + 0.f) * m_tileSize.y * m_scale);
            quad[1].position = sf::Vector2f((y + 1.f) * m_tileSize.x * m_scale, (x + 0.f) * m_tileSize.y * m_scale);
            quad[2].position = sf::Vector2f((y + 1.f) * m_tileSize.x * m_scale, (x + 1.f) * m_tileSize.y * m_scale);
            quad[3].position = sf::Vector2f((y + 0.f) * m_tileSize.x * m_scale, (x + 1.f) * m_tileSize.y * m_scale);

            quad[0].texCoords = sf::Vector2f(tu, tv);
            quad[1].texCoords = sf::Vector2f(tu + m_tileSize.x, tv);
            quad[2].texCoords = sf::Vector2f(tu + m_tileSize.x, tv + m_tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu, tv + m_tileSize.y);
        }
    }
}

void TileMap::drawTiles(sf::RenderWindow &window) const
{
    window.draw(m_vertices.data(), m_vertices.size(), sf::Quads, &m_texture);
}

void TileMap::drawPlayer(sf::RenderWindow &window) const
{
    window.draw(m_player);
}

void TileMap::drawUnits(sf::RenderWindow &window) const
{
    for (const auto &s : m_units)
        window.draw(s);
}

void TileMap::drawTexts(sf::RenderWindow &window) const
{
    for (const auto &t : m_texts)
        window.draw(t);
}
