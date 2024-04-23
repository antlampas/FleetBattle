/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

namespace fleetBattle
{
    playerBoard::playerBoard(deployedShips_t deployedShips)
    {
        if(this->checkOverlappingShips(deployedShips))
        {
            throw boardConstructionError{};
        }
        if(!this->initiateShipsLayer())
        {
            throw boardConstructionError{};
        }
        if(!this->initiateDestroyedShips())
        {
            throw boardConstructionError{};
        }
        if(this->deployShips(deployedShips))
        {
            throw boardConstructionError{};
        }
        if(this->drawDeployedShipsOnBoard())
        {
            throw boardConstructionError{};
        }
    }
}