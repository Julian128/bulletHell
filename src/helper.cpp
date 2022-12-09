#include <random>
#include <iostream>
// #include "../include/helper.h"



const int WIDTH = 3000;
const int HEIGHT = 2000;

bool onMouse;

// player stats
int money;
int health;

int level;
bool levelFinished;


int numberOfEnemies;
int enemyHealth;
float enemySpeed;
int moneyPerEnemy;

float random(float min, float max);

float bound(float input, float Min, float Max);

// get distance between two points
float dist(float aX, float aY, float bX, float bY);
onMouse = false;

// player stats
money = 1000;
health = 100;

level = 1;
levelFinished = false;

// enemy stats


// TESTING
// int numberOfEnemies = 1000;
// int enemyHealth = 5;
// float enemySpeed = 10;

numberOfEnemies = 10;
enemyHealth = 5;
enemySpeed = 0.5;
moneyPerEnemy = 1;

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

