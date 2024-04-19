/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

namespace fleetBattle
{
    void playerBoard::checkShipSunk(coordinates_t coordinates)
    {
        decodedCoordinatesPair_t decodedCoordinates = decodeCoordinates(coordinates);

        for(auto deployedShip: this->deployedShips)
        {
            if(isShipHorizontal(deployedShip))
            {

            }
            if(isShipVertical(deployedShip))
            {
                
            }
        }
    }
}