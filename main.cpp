#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "include/Player.h"
#include "include/Enemy.h"
#include "include/GameRenderer.h"
#include "include/Perks.h"
#include "include/Helpers.h"



int main()
{
    // Create the window
    GameRenderer window;
    window.setFramerateLimit(FRAMERATE);
    

    Player player;
    std::vector<Enemy> enemies;
    Perks perks;
    perks.addPerk();

    for (int i = 0; i < 10; i++)
    {
        enemies.push_back(randomEnemy());
    }


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
        player.update(window);

        // update enemies
        for (size_t i = 0; i < enemies.size(); i++)
        {
            enemies[i].updatePosition(player);
        }

        perks.usePerks(player, enemies);
        

        // Display the contents of the window on the screen
        window.renderWindow(player, enemies);

        // refresh frame
        window.display();

    }
}