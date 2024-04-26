/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "player.hpp"

#include <iostream>

namespace fleetBattle
{
    shootStatus_t player::shoot(coordinates_t c)
    {
        std::cout << "1" << std::endl;
        if(!this->ownBoard->isSquareAlreadyHit(c))
        {
            std::cout << "2" << std::endl;
            if(this->ownBoard->getSquareStatus(c) == 'S')
            {
                std::cout << "3" << std::endl;
                return this->ownBoard->setSquareStatus(c,shootReturnStatus_t::HIT);
            }
            else
            {
                std::cout << "4" << std::endl;
                return this->ownBoard->setSquareStatus(c,shootReturnStatus_t::MISSED);
            }
        }
        else
        {
            std::cout << "5" << std::endl;
            return shootReturnStatus_t::ALREADYHIT;
        }
    }
}