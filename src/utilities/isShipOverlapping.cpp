/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "utilities.hpp"

namespace fleetBattle
{
    bool isShipOverlapping(shipPosition_t a,shipPosition_t b)
    {
        bool bothHorizontal   = false;
        bool bothVertical     = false;
        bool firstHorizontal  = false;
        bool firstVertical    = false;

        if(isShipHorizontal(a) && isShipHorizontal(b))
        {
            bothHorizontal   = true;
            bothVertical     = false;
            firstHorizontal  = false;
            firstVertical    = false;
        }
        else if(isShipVertical(a) && isShipVertical(b))
        {
            bothHorizontal   = false;
            bothVertical     = true;
            firstHorizontal  = false;
            firstVertical    = false;
        }
        else if(isShipHorizontal(a))
        {
            bothHorizontal   = false;
            bothVertical     = false;
            firstHorizontal  = true;
            firstVertical    = false;
        }
        else
        {
            bothHorizontal   = false;
            bothVertical     = false;
            firstHorizontal  = false;
            firstVertical    = true;
        }

        if(bothHorizontal)
        {
            decodedCoordinatesPair_t a1 = decodeCoordinates(a.first);
            decodedCoordinatesPair_t a2 = decodeCoordinates(a.second);
            decodedCoordinatesPair_t b1 = decodeCoordinates(b.first);
            decodedCoordinatesPair_t b2 = decodeCoordinates(b.second);

            return isInlineShipsOverlapping(a1,a2,b1,b2);
        }
        else if(bothVertical)
        {
            decodedCoordinatesPair_t a1 = decodeCoordinates(a.first);
            decodedCoordinatesPair_t a2 = decodeCoordinates(a.second);
            decodedCoordinatesPair_t b1 = decodeCoordinates(b.first);
            decodedCoordinatesPair_t b2 = decodeCoordinates(b.second);

            decodedCoordinatesPair_t invA1 {a1.second,a1.first};
            decodedCoordinatesPair_t invA2 {a2.second,a2.first};
            decodedCoordinatesPair_t invB1 {b1.second,b1.first};
            decodedCoordinatesPair_t invB2 {b2.second,b2.first};

            return isInlineShipsOverlapping(invA1,invA2,invB1,invB2);
        }
        else if(firstHorizontal)
        {
            decodedCoordinatesPair_t a1 = decodeCoordinates(a.first);
            decodedCoordinatesPair_t a2 = decodeCoordinates(a.second);
            decodedCoordinatesPair_t b1 = decodeCoordinates(b.first);
            decodedCoordinatesPair_t b2 = decodeCoordinates(b.second);

            return isCrossingShipsOverlapping(a1,a2,b1,b2);
        }
        else if(firstVertical)
        {
            decodedCoordinatesPair_t a1 = decodeCoordinates(a.first);
            decodedCoordinatesPair_t a2 = decodeCoordinates(a.second);
            decodedCoordinatesPair_t b1 = decodeCoordinates(b.first);
            decodedCoordinatesPair_t b2 = decodeCoordinates(b.second);

            return isCrossingShipsOverlapping(b1,b2,a1,a2);
        }

        throw unknownError{};
    }
}