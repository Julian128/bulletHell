#pragma once

#include <iostream>
#include <vector>
#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/Helpers.h"


class GameEngine
{
public:
    GameEngine();


    void enemyDamage(Player &player, std::vector<Enemy> &enemies);

};