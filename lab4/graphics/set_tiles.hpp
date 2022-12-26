#ifndef SET_TILEMAP_HPP
#define SET_TILEMAP_HPP

#include <SFML/Graphics.hpp>
#include <sstream>
#include "config_tiles.hpp"

namespace game
{

    /// @brief class for graphics
    class TileMap
    {
    private:
        float m_scale;
        const sf::Texture &m_texture;
        const sf::Text &m_text;
        sf::Sprite m_player;
        std::list<sf::Sprite> m_units;
        std::list<sf::Text> m_texts;
        sf::Vector2i m_tileSize;
        std::vector<sf::Vertex> m_vertices;

    public:
        /// @brief  constructor
        /// @param texture  textures to use
        /// @param text text to print
        /// @param tileSize size of
        /// @param scale    scale of tiles
        TileMap(const sf::Texture &texture, const sf::Text &text, const sf::Vector2i &tileSize, float scale = 2.);

        /// @brief
        /// @param w
        void load(game::Landscape land);

        /// @brief
        /// @param window
        void drawTiles(sf::RenderWindow &window) const;

        /// @brief
        /// @param window
        void drawPlayer(sf::RenderWindow &window) const;

        /// @brief
        /// @param window
        void drawUnits(sf::RenderWindow &window) const;

        /// @brief
        /// @param window
        void drawTexts(sf::RenderWindow &window) const;
    };
}

#endif