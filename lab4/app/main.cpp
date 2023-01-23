#include <SFML/Graphics.hpp>
#include <iostream>

#include "../graphics/set_tiles.hpp"

using namespace game;

static const sf::Vector2i tile_size(16, 16);
static const float scale = 4.f;

void render(sf::RenderWindow &window, sf::Texture &texture,
            sf::Text &text, game::Landscape &game);

int main() {
    char game_name[] = "The Call of the Wild";

    auto height = MAP_SIZE_HORIZONTAL * tile_size.x * scale;
    auto width = MAP_SIZE_VERTICAL * tile_size.y * scale;

    sf::VideoMode video(height, width);
    sf::RenderWindow window(video, game_name);
    // auto window = sf::RenderWindow{{1920u, 1080u}, game_name};
    window.setFramerateLimit(60);

    char font_path[] = "../fonts_tilesets/FROGBLOCK-V2.1-by-Polyducks.ttf";
    char texture_path[] = "../fonts_tilesets/tilemap_packed.png";
    unsigned font_size = 30;

    sf::Font font_start;
    if (!font_start.loadFromFile(font_path))
        std::cout << "BAD FONT" << std::endl;

    sf::Text text_start;
    text_start.setFont(font_start);
    text_start.setString(game_name);
    text_start.setCharacterSize(font_size);
    text_start.setFillColor(sf::Color::White);
    text_start.setPosition(height / 5, width / 5);
    sf::Clock clock;
    sf::Time elapsed1 = clock.getElapsedTime();
    sf::Time elapsed2 = clock.getElapsedTime();

    font_size = 10;
    sf::Texture texture;
    texture.loadFromFile(texture_path);
    sf::Text text;
    sf::Font font;
    font.loadFromFile(font_path);
    text.setFont(font);
    text.setCharacterSize(font_size);

    bool main_menu = true;
    bool school_table = false;

    Landscape game;

    video = sf::VideoMode(height, width);
    window.create(video, game_name);

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    main_menu = !main_menu;
                } else if (event.key.code == sf::Keyboard::Up ||
                           event.key.code == sf::Keyboard::W) {
                    // up
                } else if (event.key.code == sf::Keyboard::Down ||
                           event.key.code == sf::Keyboard::S) {
                    // down
                } else if (event.key.code == sf::Keyboard::Left ||
                           event.key.code == sf::Keyboard::A) {
                    // left
                } else if (event.key.code == sf::Keyboard::Right ||
                           event.key.code == sf::Keyboard::D) {
                    // right
                } else if (event.key.code == sf::Keyboard::C) {
                    // call
                } else if (event.key.code == sf::Keyboard::E) {
                    // attack
                } else if (event.key.code == sf::Keyboard::H) {
                    // heal
                } else if (event.key.code == sf::Keyboard::X) {
                    if (!main_menu)
                        school_table = !school_table;
                } else if (event.key.code == sf::Keyboard::Enter) {
                    // commit action
                }
            }
        }

        elapsed2 = clock.getElapsedTime();

        window.clear();

        if (elapsed2.asSeconds() - elapsed1.asSeconds() <= 2)
            window.draw(text_start);
        else if (main_menu) {
            //
        } else if (school_table) {
            //
        } else {
            render(window, texture, text, game);
        }

        window.display();
    }
}

void render(sf::RenderWindow &window, sf::Texture &texture,
            sf::Text &text, game::Landscape &game) {
    TileMap tileMap(texture, text, tile_size, scale);
    tileMap.load(game);
    window.clear();
    tileMap.draw_field(window);
    tileMap.draw_texts(window);
    tileMap.draw_units(window);
}