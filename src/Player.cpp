#include "../include/Player.h"


Player::Player()
{
    // set position of player
    position = sf::Vector2f(0, 0);

    // set velocity of player
    velocity = sf::Vector2f(0, 0);

    // set health of player
    health = 100;
}

// Player constructor intitialization list
Player::Player() : position(500, 500), velocity(1, 1), health(100) {}



// void Player::move(float dt)
void Player::move()
{
    // position += velocity * dt;
    position += velocity * 1.;
}