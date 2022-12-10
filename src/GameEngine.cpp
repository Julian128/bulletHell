#include "../include/GameEngine.h"

GameEngine::GameEngine()
{
};

void GameEngine::enemyDamage(Player &player, std::vector<Enemy> &enemies)
{
    for (size_t i = 0; i < enemies.size(); i++)
    {
        if (enemies[i].getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            player.health -= 1;
            enemies.erase(enemies.begin() + i);
        }
    }
}