/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "player.hpp"

namespace fleetBattle
{
    shootStatus_t player::shoot(coordinates_t c)
    {
        if(!this->ownBoard->isSquareAlreadyHit(c))
        {
            if(this->ownBoard->getSquareStatus(c) == 'S')
            {
                return this->ownBoard->setSquareStatus(c,shootReturnStatus_t::HIT);
            }
            else
            {
                return this->ownBoard->setSquareStatus(c,shootReturnStatus_t::MISSED);
            }
        }
        else
        {
            return shootReturnStatus_t::ALREADYHIT;
        }
    }
}