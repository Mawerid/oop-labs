#include "other_func.hpp"

namespace game {

void render(sf::RenderWindow &window, sf::Texture &texture,
            sf::Text &text, game::Landscape &game,
            std::pair<int, int> current) {
    unsigned font_size = 10;
    text.setCharacterSize(font_size);

    TileMap tileMap(texture, text, tile_size, scale);
    tileMap.load(game, current);
    window.clear();
    tileMap.draw_field(window);
    tileMap.draw_units(window);
    tileMap.draw_texts(window);
}

void preview(sf::RenderWindow &window, sf::Text &text) {
    unsigned font_size = 30;

    text.setString(game_name);
    text.setCharacterSize(font_size);
    text.setFillColor(sf::Color::White);
    text.setPosition(height / 5, width / 5);
    window.draw(text);
}

void show_menu(sf::RenderWindow &window, sf::Text &text) {
    unsigned font_size = 25;

    std::ostringstream menu;

    menu << "\t\t\t" << game_name << "\n\n";
    menu << "This game for 2 players. \nWin the one, who stay alive.\n\n";
    menu << "Hotkeys:\n";
    menu << "Esc - show this menu\n";
    menu << "Q - show queue of units\n";
    menu << "V - show current unit's skills\n";
    menu << "WASD for choosing position to move your squad or \nto attack\n";
    menu << "H - heal squad(only while playing immortals)\n";
    menu << "E - to attack(only if your squad near target)\n";
    menu << "F - to attack lord(only if your squad near)\n";
    menu << "\nIf you are playing as a lord:\n";
    menu << "C - to call some squad\n";
    menu << "X - to show school table and upgrade it\n\n";
    menu << "Note: You should press Enter to make decision\n";

    text.setString(menu.str());
    text.setCharacterSize(font_size);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, width / 5);
    window.draw(text);
}

std::ostringstream get_table(squad::Lord::knowledge_type &knowlenge) {
    std::ostringstream table;
    table << "\nRobotics (0):  "
          << knowlenge.at(constant::school_type::ROBOTICS)
          << " needs " << knowlenge.begin()->first.get_skill_list()[knowlenge.at(constant::school_type::ROBOTICS) + 1].get_energy() * COEF_MIN_STUDY;
    table << "\nEnergiser (1): "
          << knowlenge.at(constant::school_type::ENERGISER)
          << " needs " << (knowlenge.begin()++)->first.get_skill_list()[knowlenge.at(constant::school_type::ENERGISER) + 1].get_energy() * COEF_MIN_STUDY;
    table << "\nParallel (2):  "
          << knowlenge.at(constant::school_type::PARALLEL)
          << " needs " << ((knowlenge.begin()++)++)->first.get_skill_list()[knowlenge.at(constant::school_type::PARALLEL) + 1].get_energy() * COEF_MIN_STUDY;
    table << "\nBiotech (3):   "
          << knowlenge.at(constant::school_type::BIOTECH)
          << " needs " << (((knowlenge.begin()++)++)++)->first.get_skill_list()[knowlenge.at(constant::school_type::BIOTECH) + 1].get_energy() * COEF_MIN_STUDY;
    table << "\nNanoslime (4): "
          << knowlenge.at(constant::school_type::NANOSLIME)
          << " needs " << ((((knowlenge.begin()++)++)++)++)->first.get_skill_list()[knowlenge.at(constant::school_type::NANOSLIME) + 1].get_energy() * COEF_MIN_STUDY;
    return table;
}

void show_school_tables(sf::RenderWindow &window, sf::Text &text,
                        game::Landscape &game) {
    unsigned font_size = 35;
    text.setCharacterSize(font_size);

    auto table_left = game.get_left_player()->get_knowledge();
    auto table_right = game.get_right_player()->get_knowledge();

    text.setString(get_table(table_left).str());
    text.setPosition(10, width / 2 - width / 3);
    text.setFillColor(sf::Color::Blue);
    window.draw(text);
    text.setString(get_table(table_right).str());
    text.setPosition(10, width / 2);
    text.setFillColor(sf::Color::Red);
    window.draw(text);
}

void show_units(sf::RenderWindow &window, sf::Text &text) {
    unsigned font_size = 25;

    std::ostringstream units_list;

    units_list << "Robomech (0)\tDendroid (8)\n";
    units_list << "Centry (1)\t  Marine (9)\n";
    units_list << "Colossus (2)\tCyclone (10)\n";
    units_list << "Ghost (3)\t   Reaper (11)\n";
    units_list << "Infestor (4)\tPoltergeist (12)\n";
    units_list << "Disruptor (5)   Typhon (13)\n";
    units_list << "Elf (6)\t\t Mimic (14)\n";
    units_list << "Gnome (7)";

    text.setString(units_list.str());
    text.setCharacterSize(font_size);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, width / 5);
    window.draw(text);
}

std::pair<unsigned, unsigned> move_current(
    std::pair<unsigned, unsigned> &current,
    int diff_vertical,
    int diff_horizontal,
    squad::Squad *unit,
    field::Point current_position) {
    unsigned speed = unit->get_speed();
    constant::unit name = unit->get_name();
    player_type type = static_cast<player_type>(unit->get_team());

    if (diff_vertical != 0) {
        if (diff_vertical == -1 && current.first > 0) {
            current.first--;
            field::Point current_as_point(current.first, current.second);
            if (current_as_point.distance(current_position) > speed &&
                name != constant::LORD)
                current.first++;
        } else if (diff_vertical == 1 &&
                   current.first < MAP_SIZE_VERTICAL - 1) {
            current.first++;
            field::Point current_as_point(current.first, current.second);
            if (current_as_point.distance(current_position) > speed &&
                name != constant::LORD)
                current.first--;
        }
    } else if (diff_horizontal != 0) {
        if (name != constant::LORD) {
            if (diff_horizontal == -1 && current.second > 2) {
                current.second--;
                field::Point current_as_point(current.first, current.second);
                if (current_as_point.distance(current_position) > speed)
                    current.second++;
            } else if (diff_horizontal == 1 &&
                       current.second < MAP_SIZE_HORIZONTAL - 3) {
                current.second++;
                field::Point current_as_point(current.first, current.second);
                if (current_as_point.distance(current_position) > speed)
                    current.second--;
            }
        } else {
            if (type == player_type::LEFT) {
                if (current.second == 0) {
                    current.second += 2;
                } else if (diff_horizontal == -1 && current.second > 2) {
                    current.second--;
                } else if (diff_horizontal == 1 &&
                           current.second < 3) {
                    current.second++;
                }
            } else {
                if (current.second == 18) {
                    current.second -= 2;
                } else if (diff_horizontal == -1 &&
                           current.second > MAP_SIZE_HORIZONTAL - 4) {
                    current.second--;
                } else if (diff_horizontal == 1 &&
                           current.second < MAP_SIZE_HORIZONTAL - 3) {
                    current.second++;
                }
            }
        }
    }
    return current;
}

void show_queue(sf::RenderWindow &window, sf::Text &text,
                Landscape::queue queue) {
    unsigned font_size = 20;

    text.setCharacterSize(font_size);
    text.setFillColor(sf::Color::White);

    text.setString("Current queue:\n");
    text.setPosition(10, 10);
    window.draw(text);

    unsigned i = 40;

    for (auto unit : queue) {
        text.setFillColor(colors.at(
            static_cast<player_type>(unit->get_team())));

        text.setString(name_to_str.at(unit->get_name()));
        text.setPosition(10, i);
        window.draw(text);
        i += 30;
    }
}

void show_skills(sf::RenderWindow &window, sf::Text &text,
                 constant::unit name) {
    unsigned font_size = 30;

    std::ostringstream skills;

    skills << name_to_str.at(name) << "\n";
    skills << "\nTYPE:       " << constant::unit_type[name];
    skills << "\nMAX HP:     " << constant::max_health[name];
    skills << "\nQUANTITY:   " << constant::max_quantity[name];
    skills << "\nSPEED:      " << constant::speed[name];
    skills << "\nEXPERIENCE: " << constant::experience[name];
    skills << "\nMOTIVATION: " << constant::motivation[name];
    skills << "\nDAMAGE:     " << constant::damage[name];
    skills << "\nSHIELD:     " << constant::shield[name];
    skills << "\nENERGY:     " << constant::energy[name];

    text.setString(skills.str());
    text.setCharacterSize(font_size);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 20);
    window.draw(text);
}

bool check_end(Landscape &game) {
    if (game.get_left_player()->get_health() <= 0 ||
        game.get_right_player()->get_health() <= 0)
        return true;
    else
        return false;
}

void show_end(sf::RenderWindow &window, sf::Text &text, player_type type) {
    unsigned font_size = 30;

    std::ostringstream message;

    message << "Player ";
    if (type == player_type::RIGHT)
        message << "RIGHT ";
    else
        message << "LEFT ";
    message << "wins!";

    text.setString(message.str());
    text.setCharacterSize(font_size);
    text.setFillColor(sf::Color::White);
    text.setPosition(height / 4, width / 5);
    window.draw(text);
}

unsigned get_school() {
    std::cout << "Enter the num of school (-1 to cancel): ";
    int school = -2;

    while (get_num(school) ||
           !(school >= 0 && school < UNITS_COUNT / UNITS_PER_SCHOOL)) {
        if (school == -1)
            throw std::invalid_argument("Cancel choosing of school");
        else
            std::cout << "Wrong input. Please, repeat: ";
    }

    return school;
}

unsigned get_unit() {
    std::cout << "Enter the num of unit (-1 to cancel): ";
    int unit = -2;

    while (get_num(unit) || !(unit >= 0 && unit < UNITS_COUNT)) {
        if (unit == -1)
            throw std::invalid_argument("Cancel choosing of unit");
        else
            std::cout << "Wrong input. Please, repeat: ";
    }

    return unit;
}

}  // namespace game