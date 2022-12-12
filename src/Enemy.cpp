#include "../include/Enemy.h"
#include "../include/Helpers.h"


Enemy::Enemy()
    : maxSpeed(10), health(100)

{

    setRadius(10);
    setFillColor(sf::Color::Blue);
    setPosition(100, 100);
    setOrigin(0, 0);
}

void Enemy::updatePosition(Player &player)
{
    sf::Vector2f difference = player.getPosition() - getPosition();
    
    float distance = std::sqrt(difference.x * difference.x + difference.y * difference.y);
    distance = std::max(1.f, distance);

    sf::Vector2f normal_direction = difference / distance;
    float speed = std::min(maxSpeed, distance);

    move(normal_direction * speed * 0.1f);
}

float Enemy::getDistance(Player &player)
{
    sf::Vector2f difference = player.getPosition() - getPosition();
    float distance = std::sqrt(difference.x * difference.x + difference.y * difference.y);
    return distance;
}


Enemy randomEnemy()
{
    Enemy enemy;
    enemy.setPosition(sf::Vector2f(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT));
    return enemy;
}

