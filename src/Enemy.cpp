#include "../include/Enemy.h"

Enemy::Enemy()
    : velocity(sf::Vector2f(1, 1)), health(100)

{

    setRadius(10);
    setFillColor(sf::Color::Blue);
    setPosition(100, 100);
    setOrigin(0, 0);
}