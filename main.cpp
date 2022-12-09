#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

const int FRAMERATE = 60;

typedef sf::Color Color;
const Color COLOR_GRAY(128, 128, 128);

using namespace sf;



int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My SFML Canvas");
    window.setFramerateLimit(FRAMERATE);

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
        }

        window.clear(COLOR_GRAY);

        // Update and draw your objects here...

        // Display the contents of the window on the screen


        window.display();
    }

    return 0;
}