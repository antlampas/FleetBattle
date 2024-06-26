/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "player.hpp"

namespace fleetBattle
{
    squareStatus_t player::setOwnBoardSquareStatus(coordinates_t c,squareStatus_t s)
    {
        this->ownBoard->setSquareStatus(c,s);

        return this->ownBoard->getSquareStatus(c);
    }
}