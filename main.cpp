#include <random>
#include <thread>
#include <chrono>
#include <string>
#include "include/enemies.h"
#include "include/turrets.h"
#include "include/helper.h"

void drawText(sf::RenderWindow &window, std::string stringText, int x, int y, int size, sf::Color color);

// void drawTurretStore(sf::RenderWindow &window, std::vector<Turret> &turretStore, int x, int y, int width, int height, int spacing)
// {
//     int i = 0;
//     for (auto &turret : turretStore)
//     {
//         turret.setPosition(x + (i * (width + spacing)), y);
//         turret.setSize(sf::Vector2f(width, height));
//         turret.setFillColor(turret.color);
//         window.draw(turret);
//         i++;
//     }
// }

void display(sf::RenderWindow &window, std::vector<Enemy> &enemies, std::vector<Turret> &turrets)
{
    for (auto &enemy : enemies)
        window.draw(enemy);

    for (auto &turret : turrets)
    {
        window.draw(turret);
        turret.drawAttackRange(window);
        drawText(window, std::to_string((int)turret.level), turret.level < 10? turret.getPosition().x-11 : turret.getPosition().x-22, turret.getPosition().y-25, 40, sf::Color::White);

    }
    window.display();
}


void updateEnemies(std::vector<Enemy> &enemies)
{
    for (size_t i = 0; i < enemies.size(); i++)
    {
        enemies[i].propagate();
        enemies[i].setFillColor(sf::Color::Red);

        // if enemies are outside the window remove them and reduce health by one
        if (enemies[i].getPosition().x > WIDTH || enemies[i].getPosition().y > HEIGHT || enemies[i].getPosition().y < 0)
        {
            enemies.erase(enemies.begin() + i);
            health--;
        }

        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void updateTurrets(std::vector<Turret> &turrets)
{
    for (auto &turret : turrets)
    {
        if (turret.activeCooldown <= 0)
            turret.setFillColor(turret.color);
        
        turret.activeCooldown -= 1;

    }
}

void turretsAttack(std::vector<Enemy> &enemies, std::vector<Turret> &turrets)
{

    for (size_t i = 0; i < turrets.size(); i++)
    {
        for (size_t j = 0; j < enemies.size(); j++)
        {

            // attacking
            if (turrets[i].attacking == true && turrets[i].activeCooldown <= 0 && dist(enemies[j].getPosition().x, enemies[j].getPosition().y, turrets[i].getPosition().x, turrets[i].getPosition().y) <= turrets[i].attackRange)
            {
                enemies[j].health -= turrets[i].attackDamage;

                enemies[j].setRadius(enemies[j].getRadius()-turrets[i].attackDamage);


                turrets[i].activeCooldown = turrets[i].attackCooldown;
                if (enemies[j].health <= 0)
                {
                    enemies.erase(enemies.begin() + j);
                    money += moneyPerEnemy;
                }



                // change turret color when on cooldown
                turrets[i].setFillColor(sf::Color::Black);
                // change enemy color when hit
                enemies[j].setFillColor(sf::Color::Black);
                

            }
        }

    }
}


std::vector<Enemy> nextLevel()
{
    health += 10;

    numberOfEnemies = (int)(numberOfEnemies*1.1 + random(2, 4));
    money += level*100;
    moneyPerEnemy++;
    level++;
    enemyHealth += random(0, 0.5);
    if (level % 5 == 0)
        enemySpeed += random(0, 0.02);
    std::vector<Enemy> enemies(numberOfEnemies);

    for (size_t i = 0; i < enemies.size(); i++)
    {
        enemies[i].setRadius(20);
        enemies[i].setPosition(random(-sqrt(numberOfEnemies)*100, 0), 100);
        enemies[i].setOrigin(enemies[i].getRadius(), enemies[i].getRadius());
        enemies[i].setFillColor(sf::Color::Red);

        if (level % 5 == 0)
            enemies[i].speed = enemySpeed*1.5;
        else
            enemies[i].speed = enemySpeed;
        enemies[i].health = enemyHealth;
    }

    printf("Enemies: %i\n", (int)enemies.size());

    // sleep between levels
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return enemies;

}

std::vector<Enemy> initialize()
{
    std::vector<Enemy> enemies(numberOfEnemies);
    for (size_t i = 0; i < enemies.size(); i++)
    {
        enemies[i].setRadius(20);
        enemies[i].setPosition(random(-numberOfEnemies*100, 0), random(100, 100));
        enemies[i].setOrigin(enemies[i].getRadius(), enemies[i].getRadius());
        enemies[i].setFillColor(sf::Color::Red);

        enemies[i].speed = enemySpeed;
        enemies[i].health = enemyHealth;
    }


    printf("Enemies: %i\n", (int)enemies.size());

    return enemies;
}


void drawText(sf::RenderWindow &window, std::string textString, int x, int y, int size, sf::Color color = sf::Color::White)
{
    sf::Text text;
    sf::Font font;

    if (!font.loadFromFile("Roboto-Black.ttf"))
        printf("Font error\n");

    text.setFont(font); // font is a sf::Font
    text.setString(textString);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(x, y);
    window.draw(text);
    }

void placeTurret(std::vector<Turret> &turrets, sf::Event &event, sf::RenderWindow &window)
{
    // place position at mouse position
    if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !onMouse) {


        for (auto &turret : turrets)
        {
            if (turret.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
                turret.upgrade();
                onMouse = true;
                return;
            }
        }


        onMouse = true;
        Turret turret;
        if (money >= turret.cost)
        {
            turret.setSize(sf::Vector2f(50, 50));
            turret.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            turret.setOrigin(turret.getSize().x / 2, turret.getSize().y / 2);
            turret.setFillColor(sf::Color::Blue);

            turret.attacking = true;
            turret.attackRange = 100;
            turret.attackCooldown = 20;
            turret.activeCooldown = 0;
            turret.attackDamage = 1;
            turret.freezeDuration = 5;

            turrets.push_back(turret);
            money -= turret.cost;
            printf("%i turrets placed\n", (int)turrets.size());
        }
    }
    if (event.type != event.MouseButtonPressed && event.mouseButton.button != sf::Mouse::Left)
        onMouse = false;

}


void gameOver()
{
    if (health <= 0)
    {
        printf("Game over\n");
        exit(0);
    }
}

int main()
{

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tower Defense");
    window.setFramerateLimit(120);

    std::vector<Enemy> enemies = initialize();

    // turrets
    std::vector<Turret> turrets;
  


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        if ((int)enemies.size() == 0)
            enemies = nextLevel();

        std::string info = "HP: " + std::to_string(health) + "   Level: " + std::to_string(level) + "   Gold: " + std::to_string(money)
        + "   Enemies: " + std::to_string(enemies.size());
        drawText(window, info, 50, HEIGHT-130, 80, sf::Color::Black);
        gameOver();
        placeTurret(turrets, event, window);
        updateEnemies(enemies);
        updateTurrets(turrets);
        turretsAttack(enemies, turrets);

        display(window, enemies, turrets);



    }

    return 0;
}

