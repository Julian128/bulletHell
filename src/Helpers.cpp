#include <random>
#include <iostream>

float random(float min, float max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<float> dist(min, max+1);

    return dist(rng);
}

// template<typename T, typename U>
// auto bound(T input, U Min, U Max)
// {
//     T result;
//     if (input >= Max)
//         result = Max;
//     else if (input <= Min)
//         result = Min;
//     else
//         result = input;

//     return result;
// }

// get distance between two points
float dist(float aX, float aY, float bX, float bY)
{
    return sqrt(pow(aX - bX, 2) + pow(aY - bY, 2));
}
