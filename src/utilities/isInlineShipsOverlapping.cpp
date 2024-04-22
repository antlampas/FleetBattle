/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "utilities.hpp"

namespace fleetBattle
{
    bool isInlineShipsOverlapping(decodedCoordinateSingle_t a1,decodedCoordinateSingle_t a2,decodedCoordinateSingle_t b1,decodedCoordinateSingle_t b2)
    {
        if(((b1 <= a1 && a1 <= b2) || (b1 <= a2 && a2 <= b2)) || ((a1 <= b1 && b1 <= a2) || (a1 <= b2 && b2 <= a2)))
            return true;
        else
            return false;
    }
}