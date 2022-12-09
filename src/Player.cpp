#include "../include/Player.h"




// Player constructor intitialization list
Player::Player() : position(500, 500), velocity(1, 1), health(100) {}



// void Player::move(float dt)
void Player::move()
{
    // position += velocity * dt;
    position += velocity;
}