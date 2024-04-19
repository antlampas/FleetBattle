/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

namespace fleetBattle
{
    bool deployShips(deployedShips_t deployedShips)
    {
        int i = 0;
        for(auto ship: deployedShips)
        {
            std::pair<decodedCoordinatesPair_t,decodedCoordinatesPair_t> decodedShipCoordinates {};
            try
            {
                decodedShipCoordinates.first  = decodeCoordinates(ship.first);
                decodedShipCoordinates.second = decodeCoordinates(ship.second);
            }
            catch(coordinatesNotValid)
            {
                throw;
            }
            catch(...)
            {
                throw unknownError{};
            }
            bool isOnSameRow            = (decodedShipCoordinates.first.first  == decodedShipCoordinates.second.first);
            bool isOnSameColumn         = (decodedShipCoordinates.first.second == decodedShipCoordinates.second.second);
            bool isVerticalOrHorizontal = !(isOnSameRow && isOnSameColumn) && (isOnSameRow || isOnSameColumn);

            if(isVerticalOrHorizontal)
            {
                this->deployedShips.at(i) = ship;
                i++;
            }
            else
            {
                throw shipNotValid{};
            }
        }
        return true;
    }
}