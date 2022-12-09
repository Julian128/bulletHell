#include <random>
#include <iostream>
// #include <SFML/Window.hpp>
// #include <SFML/Graphics.hpp>


const int WIDTH = 3000;
const int HEIGHT = 2000;

// sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tower Defense");
// window.setFramerateLimit(120);

bool onMouse = false;

// player stats
int money = 1000;
int health = 100;

int level = 1;
bool levelFinished = false;

// enemy stats


// TESTING
// int numberOfEnemies = 1000;
// int enemyHealth = 5;
// float enemySpeed = 10;

int numberOfEnemies = 10;
int enemyHealth = 5;
float enemySpeed = 0.5;
int moneyPerEnemy = 1;

float random(float min, float max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<float> dist(min, max+1); // distribution in range [1, 6]

    return ((float(rand()) / float(RAND_MAX)) * (max+1 - min)) + min;
}

float bound(float input, float Min, float Max)
{
    float result;
    if (input >= Max)
        result = Max;
    else if (input <= Min)
        result = Min;
    else
        result = input;

    return result;
}

// get distance between two points
float dist(float aX, float aY, float bX, float bY)
{
    return sqrt(pow(aX - bX, 2) + pow(aY - bY, 2));
}

