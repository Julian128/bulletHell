#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Enemy : public sf::CircleShape
{
public:
    float speed;
    float health;
    bool frozen;

    float lastY;
    bool goingRight;
    bool initialRight;


    void propagate();
};


