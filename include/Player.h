#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Player : public sf::CircleShape
{

public:
    Player();
    
    float maxSpeed;
    int health;
    void update(sf::RenderWindow &window);
};

