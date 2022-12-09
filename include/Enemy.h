#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Enemy : public sf::CircleShape
{
public:
    sf::Vector2f velocity; // access velocity.x, velocity.y
    int health;
    Enemy();

    void updatePosition();
};