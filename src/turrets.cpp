#include "helper.cpp"
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

    sf::Color color = sf::Color::Blue;

    float cost = 100;
    float upgradeCost = 100;
    float level = 1;

    // draw attack range as a circle
    void drawAttackRange(sf::RenderWindow &window){
        sf::CircleShape attackRangeCircle(attackRange);
        attackRangeCircle.setOutlineThickness(2);
        attackRangeCircle.setOutlineColor(sf::Color::Black);
        attackRangeCircle.setFillColor(sf::Color::Transparent);
        attackRangeCircle.setPosition(getPosition().x, getPosition().y);
        attackRangeCircle.setOrigin((attackRange-1), (attackRange-1));

        window.draw(attackRangeCircle);
    }

    void upgrade(){
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


};
