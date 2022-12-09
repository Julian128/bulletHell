#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Player.h"

class Enemy : public sf::CircleShape
{
public:
    float maxSpeed;
    int health;
    Enemy();

    void updatePosition(Player &player);
};

// function that returns an enemy with a random positoin
Enemy randomEnemy();