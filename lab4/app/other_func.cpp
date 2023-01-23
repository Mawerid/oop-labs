#include "../graphics/set_tiles.hpp"

namespace game {

void render(sf::RenderWindow &window, sf::Texture &texture,
            sf::Text &text, game::Landscape &game) {
    unsigned font_size = 10;
    text.setCharacterSize(font_size);

    TileMap tileMap(texture, text, tile_size, scale);
    tileMap.load(game);
    window.clear();
    tileMap.draw_field(window);
    tileMap.draw_texts(window);
    tileMap.draw_units(window);
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
    menu << "WASD for choosing position to move your squad or \nto attack\n";
    menu << "H - heal squad(only while playing immortals)\n";
    menu << "E - to attack(only if your squad near target)\n";
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
          << " needs " << knowlenge.begin()->first.get_skill_list()[knowlenge.at(constant::school_type::ROBOTICS) + 1].get_energy();
    table << "\nEnergiser (1): "
          << knowlenge.at(constant::school_type::ENERGISER)
          << " needs " << (knowlenge.begin()++)->first.get_skill_list()[knowlenge.at(constant::school_type::ENERGISER) + 1].get_energy();
    table << "\nParallel (2):  "
          << knowlenge.at(constant::school_type::PARALLEL)
          << " needs " << ((knowlenge.begin()++)++)->first.get_skill_list()[knowlenge.at(constant::school_type::PARALLEL) + 1].get_energy();
    table << "\nBiotech (3):   "
          << knowlenge.at(constant::school_type::BIOTECH)
          << " needs " << (((knowlenge.begin()++)++)++)->first.get_skill_list()[knowlenge.at(constant::school_type::BIOTECH) + 1].get_energy();

    table << "\nNanoslime (4): "
          << knowlenge.at(constant::school_type::NANOSLIME)
          << " needs " << ((((knowlenge.begin()++)++)++)++)->first.get_skill_list()[knowlenge.at(constant::school_type::NANOSLIME) + 1].get_energy();
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

void show_units(sf::RenderWindow &window, sf::Text &text,
                game::Landscape &game) {
}
}