#include "../include/GameRenderer.h"






// GameRenderer(sf::VideoMode mode, const sf::String &title, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings &settings = sf::ContextSettings())
//     : sf::RenderWindow(mode, title, style, settings) {}



GameRenderer::GameRenderer() : sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game", sf::Style::Default, sf::ContextSettings(0, 0, 8))
{
    setFramerateLimit(60);
}

void GameRenderer::renderWindow(Player &player, std::vector<Enemy> &enemies)
{

    // renders player in the center of the screen while moving the world around it
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