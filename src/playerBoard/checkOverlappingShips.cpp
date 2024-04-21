/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

namespace fleetBattle
{
    bool checkOverlappingShips(deployedShips_t deployedShips)
    {
        for(auto firstShip = deployedShips.begin();firstShip != std::prev(deployedShips.end());firstShip++)
        {
            for(auto secondShip = std::next(firstShip);firstShip != deployedShips.end();secondShip++)
            {
                if(isShipVoerlapping(*firstShip,*secondShip))
                    return true;
            }
        }
        return false;
    }
}