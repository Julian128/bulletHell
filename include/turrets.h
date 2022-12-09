#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


// turret class
class Turret : public sf::RectangleShape
{
public:
    bool attacking;
    float attackRange;
    float attackCooldown;
    float activeCooldown;
    float attackDamage;

    float freezeDuration;

    sf::Color color;

    float cost;
    float upgradeCost;
    float level;

    // draw attack range as a circle
    void drawAttackRange(sf::RenderWindow &window);

    void upgrade();


};
