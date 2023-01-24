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

    squad::Squad* current_squad;
    std::pair<unsigned, unsigned> current;
    std::pair<unsigned, unsigned> previous;
    field::Point current_position;

    int diff_vertical = 0;
    int diff_horizontal = 0;

    Landscape game;

    game.play_next('c', {0, 7, 4});
    game.play_next('c', {3, 7, 6});

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
            previous = current;
            command = 'o';
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
                } else if (event.key.code == sf::Keyboard::F) {
                    command = 'f';
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

        try {
            switch (command) {
                case 'm': {
                    if (previous != current)
                        previous = current;
                    current = move_current(current, diff_vertical,
                                           diff_horizontal,
                                           current_squad,
                                           current_position);
                    if (game.get_map()[current.first]
                                      [current.second]
                                          .get_type() ==
                        field::cell_type::OBSTAClE)
                        current = previous;
                } break;
                case 'a': {
                    if (game.get_map()[current.first]
                                      [current.second]
                                          .get_type() ==
                        field::cell_type::BUSY) {
                        unsigned from_x = current_position.get_x();
                        unsigned from_y = current_position.get_y();
                        game.play_next('a', {from_x, from_y, previous.first, previous.second, current.first, current.second});
                        command = 'n';
                    }
                } break;
                case 'f': {
                    field::Point curr_as_point(current.first, current.second);
                    field::Point left_pos(MAP_SIZE_VERTICAL / 2, 0);
                    field::Point right_pos(MAP_SIZE_VERTICAL / 2,
                                           MAP_SIZE_HORIZONTAL - 1);
                    if (curr_as_point.distance(left_pos) < 3) {
                        game.play_next('a', {0, 0, 0, 0,
                                             MAP_SIZE_VERTICAL / 2, 0});
                        command = 'n';
                    } else if (curr_as_point.distance(right_pos) < 3) {
                        game.play_next('a', {0, 0, 0, 0,
                                             MAP_SIZE_VERTICAL / 2,
                                             MAP_SIZE_HORIZONTAL - 1});
                        command = 'n';
                    }
                } break;
                case 'u': {
                    if (current_squad->get_name() == constant::unit::LORD) {
                        // unsigned unit = get_unit();
                    }
                } break;
                case 'h': {
                    if (constant::unit_type[current_squad->get_name()] == "IM" || constant::unit_type[current_squad->get_name()] == "IA") {
                        game.play_next('h', {});
                        command = 'n';
                    }
                } break;
                case 'c': {
                    if (current_squad->get_name() == constant::unit::LORD) {
                        // unsigned unit = get_unit();
                    }
                } break;
                default:
                    break;
            }

            if (ready_to_do && current_squad->get_name() == constant::unit::LORD) {
                game.play_next('p', {});
                command = 'n';
            } else if (ready_to_do &&
                       game.get_map()[current.first][current.second].get_type() == field::cell_type::FREE) {
                unsigned from_x = current_position.get_x();
                unsigned from_y = current_position.get_y();
                game.play_next('m', {from_x, from_y, current.first,
                                     current.second});
                command = 'n';
            } else if (ready_to_do &&
                       game.get_map()[current.first][current.second].get_type() == field::cell_type::BUSY &&
                       previous != current) {
                unsigned from_x = current_position.get_x();
                unsigned from_y = current_position.get_y();
                game.play_next('a', {from_x, from_y,
                                     previous.first, previous.second,
                                     current.first, current.second});
                command = 'n';
            } else if (ready_to_do) {
                game.play_next('p', {});
                command = 'n';
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }

        is_end = check_end(game);

        if (is_end && ready_to_do)
            window.close();

        if (command != 'n')
            command = 'o';

        if (ready_to_do)
            ready_to_do = false;
    }

    return 0;
}
