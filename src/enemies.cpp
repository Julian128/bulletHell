#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Enemy : public sf::CircleShape
{
public:
    float speed;
    float health;
    bool frozen = false;

    float lastY = -200;
    bool goingRight = true;
    bool initialRight = true;


    void propagate() {

        // going right
        if (getPosition().x <= WIDTH*0.9 && goingRight == true && initialRight == true)
        {
            move(speed, 0);
            lastY = getPosition().y;
        }

        // going down
        else if (getPosition().x > WIDTH*0.9 && getPosition().y <= lastY + 200)
        {
            initialRight = false;
            move(0, speed);
            goingRight = false;
        }

        // going left
        else if (getPosition().x >= WIDTH*0.1 && goingRight == false)
        {
            move(-speed, 0);
            lastY = getPosition().y;
        }

        // going down on the left side
        else if (getPosition().x < WIDTH*0.1 && getPosition().y <= lastY + 200)
        {
            move(0, speed);
            goingRight = true;
        }
        
        // going right again
        else if (getPosition().x <= WIDTH*0.9 && goingRight == true)
        {
            move(speed, 0);
            lastY = getPosition().y;
        }
    }
};


