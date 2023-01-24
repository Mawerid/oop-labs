#include "set_tiles.hpp"

#include <iostream>

namespace game {
TileMap::TileMap(const sf::Texture &texture, const sf::Text &text,
                 const sf::Vector2i &size, float scale)
    : texture_(texture), text_(text), size_(size), scale_(scale) {}

void TileMap::load(game::Landscape &game, std::pair<int, int> current) {
    Landscape::map_type &map = game.get_map();
    Landscape::queue &unit_list = game.get_units_list();

    const int height = game.size_.first;
    const int width = game.size_.second;

    vertices_.resize(width * height * 4);

    for (int x = 0; x < height; ++x) {
        for (int y = 0; y < width; ++y) {
            const field::cell_type type = map[x][y].get_type();
            std::pair<int, int> coords = field_coords.at(type);

            if (x == current.first && y == current.second) {
                coords = current_to_move;
            }

            const float tu = coords.first;
            const float tv = coords.second;

            sf::Vertex *quad = &vertices_[(y + x * width) * 4];

            quad[0].position = sf::Vector2f((y + 0.f) * size_.x * scale_,
                                            (x + 0.f) * size_.y * scale_);
            quad[1].position = sf::Vector2f((y + 1.f) * size_.x * scale_,
                                            (x + 0.f) * size_.y * scale_);
            quad[2].position = sf::Vector2f((y + 1.f) * size_.x * scale_,
                                            (x + 1.f) * size_.y * scale_);
            quad[3].position = sf::Vector2f((y + 0.f) * size_.x * scale_,
                                            (x + 1.f) * size_.y * scale_);

            quad[0].texCoords = sf::Vector2f(tu, tv);
            quad[1].texCoords = sf::Vector2f(tu + size_.x, tv);
            quad[2].texCoords = sf::Vector2f(tu + size_.x, tv + size_.y);
            quad[3].texCoords = sf::Vector2f(tu, tv + size_.y);
        }
    }

    std::pair<int, int> coords;
    int tu = coords.first;
    int tv = coords.second;
    for (auto &unit : unit_list) {
        sf::Sprite sprite(texture_);
        sf::Text unit_text(text_);
        std::ostringstream unit_status;

        if (unit->get_name() == constant::unit::LORD) {
            auto *lord = static_cast<squad::Lord *>(unit);
            unit_status << "HEAL: " << lord->get_health()
                        << "\nEXP:  " << lord->get_experience()
                        << "\nENG:  " << lord->get_energy();
        } else {
            unit_status << unit->get_health();
        }

        unit_text.setString(unit_status.str());
        unit_text.setFillColor(
            colors.at(static_cast<player_type>(unit->get_team())));

        auto position = game.find_squad(unit);

        if (unit->get_name() == constant::unit::LORD) {
            if (static_cast<player_type>(unit->get_team()) == player_type::RIGHT) {
                unit_text.setPosition(position.get_y() * size_.y * scale_ - 40,
                                      position.get_x() * size_.x * scale_ - 40);
            } else {
                unit_text.setPosition(position.get_y() * size_.y * scale_,
                                      position.get_x() * size_.x * scale_ - 40);
            }
        } else {
            unit_text.setPosition(position.get_y() * size_.y * scale_,
                                  position.get_x() * size_.x * scale_ - 20);
        }

        if (unit->get_name() == constant::unit::LORD)
            coords = players_coords.at(
                static_cast<player_type>(unit->get_team()));
        else
            coords = units_coords.at(unit->get_name());

        tu = coords.second;
        tv = coords.first;

        sprite.setTextureRect({tu, tv, size_.x, size_.y});

        sprite.setPosition(position.get_y() * size_.y * scale_,
                           position.get_x() * size_.x * scale_);

        if (static_cast<player_type>(unit->get_team()) == player_type::RIGHT) {
            sprite.scale(-1.f, 1.f);
            sprite.setPosition((position.get_y() + 1) * size_.y * scale_,
                               position.get_x() * size_.x * scale_);
        }

        if (unit->get_health() == 0) {
            sprite.setOrigin(0, size_.y);
            sprite.setRotation(90.f);
        }

        sprite.scale(scale_, scale_);
        units_.push_back(sprite);
        texts_.push_back(unit_text);
    }
}

void TileMap::draw_field(sf::RenderWindow &window) const {
    window.draw(vertices_.data(), vertices_.size(), sf::Quads, &texture_);
}

void TileMap::draw_units(sf::RenderWindow &window) const {
    for (const auto &squad : units_)
        window.draw(squad);
}

void TileMap::draw_texts(sf::RenderWindow &window) const {
    for (const auto &text : texts_)
        window.draw(text);
}
}  // namespace game