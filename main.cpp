#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "include/Player.h"

const int FRAMERATE = 60;

typedef sf::Color Color;
const Color COLOR_GRAY(128, 128, 128);

using namespace sf;

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My SFML Canvas");
    window.setFramerateLimit(FRAMERATE);

    Player player;

    sf::Vector2i mousePos;

    // Main loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close the window when the user requests it
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved)
            {
                // handleMovement(event)
                mousePos = sf::Mouse::getPosition(window);
                std::cout << "Mouse position: " << mousePos.x << ", " << mousePos.y << std::endl;
            }
        }

        window.clear(COLOR_GRAY);

        // Update and draw your objects here...
        player.update(event, window);


        // Display the contents of the window on the screen

        window.draw(player);
        window.display();
    }

    return 0;
}