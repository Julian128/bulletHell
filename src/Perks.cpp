#include "../include/Perks.h"


/*

WEAPON IDEAS

- aoe damage around player
- damage enemies in a line
- damage enemies in a cone (like a shotgun)
- continous flamethrower
- continous laser
- lighting bolt
- granade on mouse pointer
- knockback
- slow
- poison
- stun
- shield
- heal




*/


basePerk::basePerk()
{
    name = "";
    cooldown = 5;
    runningCooldown = 0;
    level = 1;
}

// void basePerk::use(Player &player, std::vector<Enemy> &enemies)
// {
//     std::cout << "used";
// }


// void aoe::use(Player &player, std::vector<Enemy> &enemies)
// {
//     // check if the weapon is on cooldown
//     if (runningCooldown > 0)
//     {
//         // if it is, decrement the cooldown
//         runningCooldown--;
//     }
//     else
//     {
//         // damage all enemies in range
//         for (size_t i = 0; i < enemies.size(); i++)
//         {
//             if (enemies[i].getDistance(player) < range)
//             {
//                 enemies[i].health -= damage;
//                 std::cout << "enemy health: " << enemies[i].health << std::endl;

//                 // kill the enemy if it's health is 0 or less
//                 if (enemies[i].health <= 0)
//                     enemies.erase(enemies.begin() + i);
//             }
//         }

//     }
// }


Perks::Perks()
{

}


// void Perks::addPerk(std::unique_ptr<basePerk> perk)
void Perks::addPerk()
{
    // allPerks.emplace_back(perk);
    // allPerks.push_back(perk);
    perks.push_back(new aoe);

}


    // method to use all active perks
void Perks::usePerks(Player &player, std::vector<Enemy> &enemies)
{
    // check if the perk is active
    for (auto &perk : perks)
    {
        perk->use(player, enemies);
    }

}
