/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "utilities.hpp"

namespace fleetBattle
{
    bool isShipVertical(shipPosition_t position)
    {
        decodedCoordinatesPair_t decodedCoordinates1 {};
        decodedCoordinatesPair_t decodedCoordinates2 {};

        if(isCoordinatesValid(position.first) && isCoordinatesValid(position.second))
        {
            decodedCoordinates1 = decodeCoordinates(position.first);
            decodedCoordinates2 = decodeCoordinates(position.second);
        }
        else
        {
            throw coordinatesNotValid{};
        }

        bool isOnSameRow    = (decodedCoordinates1.first  == decodedCoordinates2.first);
        bool isOnSameColumn = (decodedCoordinates1.second == decodedCoordinates2.second);
        
        return (!isOnSameRow && isOnSameColumn);
    }
}