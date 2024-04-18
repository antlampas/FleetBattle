/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "utilities.hpp"

namespace fleetBattle
{
    bool isCrossingShipsOverlapping(decodedCoordinatesPair_t a1,decodedCoordinatesPair_t a2,decodedCoordinatesPair_t b1,decodedCoordinatesPair_t b2)
    {
        if((b1.first <= a1.first && a1.first <= b2.first) && (a1.second <= b1.second && b1.second <= a2.second))
            return true;
        else
            return false;
    }
}