#include <SFML/Graphics.hpp>
#include <iostream>

#include "other_func.hpp"

using namespace game;

int main() {
    sf::VideoMode video(height, width);
    sf::RenderWindow window(video, game_name);
    window.setFramerateLimit(60);

    sf::Clock clock;
    sf::Time elapsed1 = clock.getElapsedTime();
    sf::Time elapsed2 = clock.getElapsedTime();

    sf::Texture texture;
    sf::Text text;
    sf::Font font;
    texture.loadFromFile(texture_path);
    font.loadFromFile(font_path);
    text.setFont(font);

    bool main_menu = true;
    bool school_table = false;
    bool ready_to_do = false;
    bool call_squad = false;

    char command = 'n';
    std::vector<unsigned> args;

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
                    // do something
                    command = 'm';
                } else if (event.key.code == sf::Keyboard::Down ||
                           event.key.code == sf::Keyboard::S) {
                    // do something
                    command = 'm';
                } else if (event.key.code == sf::Keyboard::Left ||
                           event.key.code == sf::Keyboard::A) {
                    // do something
                    command = 'm';
                } else if (event.key.code == sf::Keyboard::Right ||
                           event.key.code == sf::Keyboard::D) {
                    // do something
                    command = 'm';
                } else if (event.key.code == sf::Keyboard::C) {
                    if (!main_menu && !school_table && !ready_to_do)
                        call_squad = !call_squad;
                    command = 'c';
                } else if (event.key.code == sf::Keyboard::E) {
                    command = 'a';
                } else if (event.key.code == sf::Keyboard::H) {
                    command = 'h';
                } else if (event.key.code == sf::Keyboard::X) {
                    if (!main_menu && !call_squad && !ready_to_do)
                        school_table = !school_table;
                    command = 'u';
                } else if (event.key.code == sf::Keyboard::Enter) {
                    ready_to_do = true;
                }
            }
        }

        elapsed2 = clock.getElapsedTime();

        window.clear();

        if (elapsed2.asSeconds() - elapsed1.asSeconds() <= 2)
            preview(window, text);
        else if (main_menu) {
            show_menu(window, text);
        } else if (school_table) {
            show_school_tables(window, text, game);
        } else if (call_squad) {
            show_school_tables(window, text, game);
        } else {
            render(window, texture, text, game);
        }

        window.display();
    }
}
