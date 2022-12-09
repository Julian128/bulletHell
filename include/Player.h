#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>



sf:Vector2f

class Player : public sf::CircleShape
{
public:

    // position of player
    sf::Vector2f position;
    
    // veliocity of player
    sf::Vector2f velocity; // access velocity.x, velocity.y

    // health of player
    int health;

    void move();

}

