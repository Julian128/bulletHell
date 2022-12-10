#pragma once

#include <random>
#include <iostream>
#include <SFML/Graphics.hpp>

float random(float min, float max);

template<typename U>
// auto bound(T input, U Min, U Max);

// get distance between two points
float dist(float aX, float aY, float bX, float bY);


// GLOBAL CONSTANTS

// window size
const int WINDOW_WIDTH = 2000;
const int WINDOW_HEIGHT = 1200;
const int FRAMERATE = 60;
const sf::Color COLOR_GRAY(128, 128, 128);
