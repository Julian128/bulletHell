#include "../include/Player.h"

// Player constructor intitialization list
Player::Player() : velocity(1, 1), health(100)
{
    setRadius(20);
    setPosition(100, 100);
    setFillColor(sf::Color::Red);
    //setOrigin(0, 0);
}


void Player::update(sf::Event &event, sf::RenderWindow &window)
{

    if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        // find difference of player and mouse position
        sf::Vector2f difference = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) - getPosition();
        move(difference*0.05f);

    }



}
