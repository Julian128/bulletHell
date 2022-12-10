#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


#include "../include/Player.h"
#include "../include/Enemy.h"
#include "../include/Helpers.h"

class GameRenderer : public sf::RenderWindow
{
public:

    GameRenderer();
    void renderWindow(Player &player, std::vector<Enemy> &enemies);


};