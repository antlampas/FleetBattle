/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "player.hpp"

namespace fleetBattle
{
    squareStatus_t player::setOtherBoardSquareStatus(coordinates_t,squareStatus_t)
    {
        this->otherBoard->setSquareStatus(c,s);

        return this->otherBoard->getSquareStatus(c);
    }
}