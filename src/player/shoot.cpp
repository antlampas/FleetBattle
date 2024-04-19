/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "player.hpp"

namespace fleetBattle
{
    shootStatus_t player::shoot(coordinates_t coordinates)
    {
        shootStatus_t status {this->ownBoard->shoot(coordinates)};
        
        return status;
    }
}