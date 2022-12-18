#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/landscape.hpp"

int main()
{
    auto window = sf::RenderWindow{{1920u, 1080u}, "The Call of the Wild"};
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("RobotoBold.ttf"))
    {
        std::cout << "BAD FONT" << std::endl;
    }

    sf::Text text;
    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString("The Call of the Wild!");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::White);

    // set the text style
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    // inside the main loop, between window.clear() and window.display()
    window.draw(text);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
}