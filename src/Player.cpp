#include "../include/Player.h"
#include <algorithm>
#include <cmath>
// Player constructor intitialization list
Player::Player() : maxSpeed(200.f), health(100)
{
    setRadius(20);
    setPosition(100, 100);
    setFillColor(sf::Color::Red);
    setOrigin(20, 20);
    // speed = 0.005f;
}

void Player::update(sf::RenderWindow &window)
{

    sf::Vector2f difference = sf::Vector2f(sf::Mouse::getPosition(window)) - window.getView().getCenter();
    float distance = std::sqrt(difference.x * difference.x + difference.y * difference.y);
    distance = std::max(1.f, distance);

    sf::Vector2f normal_direction = difference / distance;
    float speed = std::min(maxSpeed, distance);

    move(normal_direction * speed * 0.02f);
}
