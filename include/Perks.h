#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "../include/Player.h"
#include "../include/Enemy.h"



class basePerk
{
    public:

    std::string name;
    float cooldown;
    float runningCooldown;
    int level;

    basePerk();


    // method to use the weapon
    virtual void use(Player &player, std::vector<Enemy> &enemies) = 0;

};


class aoe : public basePerk
{
public:
    float damage = 1;

    float range = 100;

    aoe() = default;

    void use(Player &player, std::vector<Enemy> &enemies) override
    {
        printf("aoe used\n");
        // check if the weapon is on cooldown
        if (runningCooldown > 0)
        {
            // if it is, decrement the cooldown
            runningCooldown--;
        }
        else
        {
            // damage all enemies in range
            for (size_t i = 0; i < enemies.size(); i++)
            {
                if (enemies[i].getDistance(player) < range)
                {
                    enemies[i].health -= damage;
                    std::cout << "enemy health: " << enemies[i].health << std::endl;

                    // kill the enemy if it's health is 0 or less
                    if (enemies[i].health <= 0)
                        enemies.erase(enemies.begin() + i);
                }
            }

        }
    }
};

class Perks
{
    // list of all perks and their activation status and level



public:
    // std::vector<std::unique_ptr<basePerk>> allPerks = {std::unique_ptr<aoe>(new aoe)};
    std::vector<basePerk*> perks;

    Perks();
    // add a perk to the list
    void addPerk();

    // method to use all active perks
    void usePerks(Player &player, std::vector<Enemy> &enemies);


};
