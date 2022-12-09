#include "helper.cpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../include/turrets.h"



// draw attack range as a circle
void Turret::drawAttackRange(sf::RenderWindow &window){
    sf::CircleShape attackRangeCircle(attackRange);
    attackRangeCircle.setOutlineThickness(2);
    attackRangeCircle.setOutlineColor(sf::Color::Black);
    attackRangeCircle.setFillColor(sf::Color::Transparent);
    attackRangeCircle.setPosition(getPosition().x, getPosition().y);
    attackRangeCircle.setOrigin((attackRange-1), (attackRange-1));

    window.draw(attackRangeCircle);
}

void Turret::upgrade(){
    if (upgradeCost <= money){
        attackRange += 25;
        attackDamage *= 1.25;
        attackCooldown *= 0.9;

        // setSize(sf::Vector2f(getSize().x + 1, getSize().y + 1));
        money -= upgradeCost;
        upgradeCost += 100;
        level += 1;
    }

}

