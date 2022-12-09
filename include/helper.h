#pragma once

#include <random>
#include <iostream>


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