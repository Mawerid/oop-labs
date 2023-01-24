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
    bool queue = false;
    bool skills = false;
    bool is_end = false;

    char command = 'n';
    // std::vector<unsigned> args;

    squad::Squad *current_squad;
    std::pair<unsigned, unsigned> current;
    field::Point current_position;

    int diff_vertical = 0;
    int diff_horizontal = 0;

    Landscape game;

    video = sf::VideoMode(height, width);
    window.create(video, game_name);

    while (window.isOpen()) {
        if (command == 'n') {
            current_squad = game.get_next();
            current_position = game.find_squad(game.get_next());

            // if (current_position == game.find_squad(game.get_left_player()))
            //     current_position.set_y(16);
            // else if (current_position ==
            //          game.find_squad(game.get_right_player()))
            //     current_position.set_y(3);
            current = {current_position.get_x(), current_position.get_y()};
        }

        diff_vertical = 0;
        diff_horizontal = 0;

        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    main_menu = !main_menu;
                } else if (event.key.code == sf::Keyboard::Up ||
                           event.key.code == sf::Keyboard::W) {
                    diff_vertical--;
                    command = 'm';
                } else if (event.key.code == sf::Keyboard::Down ||
                           event.key.code == sf::Keyboard::S) {
                    diff_vertical++;
                    command = 'm';
                } else if (event.key.code == sf::Keyboard::Left ||
                           event.key.code == sf::Keyboard::A) {
                    diff_horizontal--;
                    command = 'm';
                } else if (event.key.code == sf::Keyboard::Right ||
                           event.key.code == sf::Keyboard::D) {
                    diff_horizontal++;
                    command = 'm';
                } else if (event.key.code == sf::Keyboard::C) {
                    if (!main_menu && !school_table &&
                        !ready_to_do && !queue && !skills)
                        call_squad = !call_squad;
                    command = 'c';
                } else if (event.key.code == sf::Keyboard::E) {
                    command = 'a';
                } else if (event.key.code == sf::Keyboard::H) {
                    command = 'h';
                } else if (event.key.code == sf::Keyboard::X) {
                    if (!main_menu && !call_squad &&
                        !ready_to_do && !queue && !skills)
                        school_table = !school_table;
                    command = 'u';
                } else if (event.key.code == sf::Keyboard::Q) {
                    if (!main_menu && !school_table &&
                        !ready_to_do && !call_squad && !skills)
                        queue = !queue;
                } else if (event.key.code == sf::Keyboard::V) {
                    if (!main_menu && !school_table &&
                        !ready_to_do && !call_squad && !queue)
                        skills = !skills;
                } else if (event.key.code == sf::Keyboard::Enter) {
                    ready_to_do = true;
                }
            }
        }

        elapsed2 = clock.getElapsedTime();

        window.clear();

        if (elapsed2.asSeconds() - elapsed1.asSeconds() <= 2)
            preview(window, text);
        else if (is_end) {
            if (game.get_left_player()->get_health() <= 0)
                show_end(window, text, player_type::RIGHT);
            else if (game.get_right_player()->get_health() <= 0)
                show_end(window, text, player_type::LEFT);
        } else if (main_menu) {
            show_menu(window, text);
        } else if (school_table) {
            show_school_tables(window, text, game);
        } else if (call_squad) {
            show_units(window, text);
        } else if (queue) {
            show_queue(window, text, game.get_units_list());
        } else if (skills) {
            show_skills(window, text, current_squad->get_name());
        } else {
            render(window, texture, text, game, current);
        }

        window.display();

        switch (command) {
            case 'm': {
                auto tmp = current;
                current = move_current(current, diff_vertical,
                                       diff_horizontal,
                                       current_squad->get_speed(),
                                       current_position);
                if (game.get_map()[current.first][current.second].get_type() == field::cell_type::OBSTAClE)
                    current = tmp;
            } break;
            case 'a':

                break;
            case 'u':
                break;
            case 'h':
                break;
            case 'c':
                break;
            default:
                break;
        }

        if (ready_to_do && game.get_map()[current.first][current.second].get_type() == field::cell_type::FREE) {
            game.play_next('m', {current.first, current.second});
        } else if (ready_to_do) {
            game.play_next('p', {});
        }

        is_end = check_end(game);

        if (is_end && ready_to_do)
            window.close();

        command = 'o';
    }
}
