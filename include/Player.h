#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


class Player : public sf::CircleShape
{
public:

    // position of player
    // sf::Vector2f position;
    
    // veliocity of player
    sf::Vector2f velocity; // access velocity.x, velocity.y

    // health of player
    int health;

    // constructor
    Player();

    void update(sf::Event &event, sf::RenderWindow &window);


// 
};

