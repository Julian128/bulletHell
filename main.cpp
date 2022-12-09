#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "include/Player.h"
#include "include/Enemy.h"
#include "include/Helpers.h"

typedef sf::Color Color;
const Color COLOR_GRAY(128, 128, 128);


class GameRenderer : public sf::RenderWindow
{
public:

    void renderWindow(Player &player, std::vector<Enemy> &enemies)
    {
        sf::Vector2f translation = player.getPosition();
        translation -= sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);        

        player.move(-translation);
        draw(player);
        player.move(translation);

        // draw enemies
        for (size_t i = 0; i < enemies.size(); i++)
        {
            enemies[i].move(-translation);
            draw(enemies[i]);
            enemies[i].move(translation);
        }

        // projectiles

        // other objects
    }


    GameRenderer(sf::VideoMode mode, const sf::String &title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings &settings = sf::ContextSettings())
        : sf::RenderWindow(mode, title, style, settings) {}
};


int main()
{
    // Create the window
    GameRenderer window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Reverse Bullet Hell");
    window.setFramerateLimit(FRAMERATE);
    

    Player player;
    std::vector<Enemy> enemies;

    for (int i = 0; i < 10; i++)
    {
        enemies.push_back(randomEnemy());
    }

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
                // std::cout << "Mouse position: " << mousePos.x << ", " << mousePos.y << std::endl;
            }
        }

        window.clear(COLOR_GRAY);

        // Update and draw your objects here...
        player.update(window);

        // update enemies
        for (size_t i = 0; i < enemies.size(); i++)
        {
            enemies[i].updatePosition(player);
        }

        // Display the contents of the window on the screen


        window.renderWindow(player, enemies);

        // refresh frame
        window.display();

    }
}