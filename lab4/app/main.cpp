#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/landscape.hpp"
#include "../graphics/set_tiles.hpp"
#include "setup.hpp"

using namespace std;

static const sf::Vector2i tileSize(16, 16);
static const float scale = 4.f;
static const string wrap = "========================================================================================\n";

void render(sf::RenderWindow &window, sf::Texture &texture, sf::Text &text, game::Landscape &land)
{
    TileMap tileMap(texture, text, tileSize, scale);
    tileMap.load(land);
    window.clear();
    tileMap.drawTiles(window);
    tileMap.drawPlayer(window);
    tileMap.drawUnits(window);
    tileMap.drawTexts(window);
    window.display();
}
/*
void talent_dialog(Landscape &land)
{
    ;

    int choice = 0;
    while (true)
    {
        system("clear 2>/dev/null");
        Player &p = w.getPlayerEnt();
        const TalentConfig &tc = p.getTalentConfig();
        uint max_levels_by_num[]{tc.WitheringMaxLevel, tc.CurseMaxLevel, tc.NecromancyMaxLevel, tc.MorphismMaxLevel,
                                 tc.UltimateMaxLevel};

        cout << wrap << "\n\t\t\tPlayer stats"
                        "\n\n\tLevel:     "
             << p.getLevel() << "   (" << p.getExp() << " / " << tc.ExpPerLevel << " exp)"
                                                                                   "\n\tMax HP:    "
             << p.getMaxHp() << "\n\tMax Mana:  " << p.getMaxMana() << "\n\tATK:       " << p.getAtk() << endl
             << endl;
        cout << wrap << "\n\t\t\tTalents upgrade (available points: " << p.getTalentPoints() << ")"
                                                                                                "\n\n\t1. Withering (level "
             << p.getTalentLevel(WITHERING) << " / " << tc.WitheringMaxLevel << ")"
                                                                                "\n\t2. Curse (level "
             << p.getTalentLevel(CURSE) << " / " << tc.CurseMaxLevel << ")"
                                                                        "\n\t3. Necromancy (level "
             << p.getTalentLevel(NECROMANCY) << " / " << tc.NecromancyMaxLevel << ")"
                                                                                  "\n\t4. Morphism (level "
             << p.getTalentLevel(MORPHISM) << " / " << tc.MorphismMaxLevel << ")"
                                                                              "\n\t5. Ultimate (level "
             << p.getTalentLevel(ULTIMATE) << " / " << tc.UltimateMaxLevel << ")"
                                                                              "\n\n\t0. back"
             << endl
             << endl;
        Input::getNumInRange(choice, 0, 5);

        if (choice == 0)
            return;
        Talent tal = talent_by_num[choice - 1];
        uint max_level = max_levels_by_num[choice - 1];
        if (p.getTalentPoints() <= 0)
            cout << "-   Not enough talent points!" << endl;
        else if (p.getTalentLevel(tal) >= max_level)
            cout << "-   This talent is at Max level!" << endl;
        else
        {
            p.setTalentPoints(p.getTalentPoints() - 1);
            p.setTalentLevel(tal, p.getTalentLevel(tal) + 1);
            cout << "+   Talent upgraded!   +" << endl;
        }
        sleep(1);
    };
} */

int main()
{
    cout << "hello" << endl;
    auto window = sf::RenderWindow{{1920u, 1080u}, "The Call of the Wild"};
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("../fonts_tilesets/FROGBLOCK-V2.1-by-Polyducks.ttf"))
        std::cout << "BAD FONT" << std::endl;

    sf::Text text;
    text.setFont(font);
    text.setString("The Call of the Wild");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(400.f, 480.f);
    sf::Clock clock;
    sf::Time elapsed1 = clock.getElapsedTime();
    sf::Time elapsed2 = clock.getElapsedTime();

    cout << "hello" << endl;

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        elapsed2 = clock.getElapsedTime();

        window.clear();

        if (elapsed2.asSeconds() - elapsed1.asSeconds() <= 3)
            window.draw(text);
        else
        {
        }

        window.display();
    }
    
}