#ifndef SET_TILEMAP_HPP
#define SET_TILEMAP_HPP

#include <SFML/Graphics.hpp>
#include <list>
#include <sstream>

#include "config_textures.hpp"

namespace game {

/// @brief class for render map
class TileMap {
   private:
    float scale_;
    const sf::Texture &texture_;
    const sf::Text &text_;
    std::list<sf::Sprite> units_;
    std::list<sf::Text> texts_;
    sf::Vector2i size_;
    std::vector<sf::Vertex> vertices_;

   public:
    /// @brief  constructor
    /// @param texture  textures to use
    /// @param text text to print
    /// @param size size of window
    /// @param scale    scale of tiles
    TileMap(const sf::Texture &texture, const sf::Text &text,
            const sf::Vector2i &size, float scale = 2.0);

    ~TileMap() = default;

    /// @brief
    /// @param game
    void load(game::Landscape &game);

    /// @brief
    /// @param window
    void draw_field(sf::RenderWindow &window) const;

    /// @brief
    /// @param window
    void draw_units(sf::RenderWindow &window) const;

    /// @brief
    /// @param window
    void draw_texts(sf::RenderWindow &window) const;
};

void show_menu();
}  // namespace game

#endif