#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player : public sf::CircleShape
{

public:
    float maxSpeed;
    int health;
    Player();
    void update(sf::RenderWindow &window);
};

