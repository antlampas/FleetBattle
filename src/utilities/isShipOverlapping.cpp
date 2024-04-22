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
        bool bothHorizontal  {false};
        bool bothVertical    {false};
        bool firstHorizontal {false};
        bool firstVertical   {false};

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
        else if(isShipHorizontal(a) && isShipVertical(b))
        {
            bothHorizontal   = false;
            bothVertical     = false;
            firstHorizontal  = true;
            firstVertical    = false;
        }
        else if(isShipVertical(a) && isShipHorizontal(b))
        {
            bothHorizontal   = false;
            bothVertical     = false;
            firstHorizontal  = false;
            firstVertical    = true;
        }
        else
        {
            throw shipNotValid{};
        }

        if(bothHorizontal)
        {
            decodedCoordinatesPair_t a1 = decodeCoordinates(a.first);
            decodedCoordinatesPair_t a2 = decodeCoordinates(a.second);
            decodedCoordinatesPair_t b1 = decodeCoordinates(b.first);
            decodedCoordinatesPair_t b2 = decodeCoordinates(b.second);

            return isInlineShipsOverlapping(a1.second,a2.second,b1.second,b2.second);
        }
        else if(bothVertical)
        {
            decodedCoordinatesPair_t a1 = decodeCoordinates(a.first);
            decodedCoordinatesPair_t a2 = decodeCoordinates(a.second);
            decodedCoordinatesPair_t b1 = decodeCoordinates(b.first);
            decodedCoordinatesPair_t b2 = decodeCoordinates(b.second);

            return isInlineShipsOverlapping(a1.first,a2.first,b1.first,b2.first);
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
        else
        {
            throw unknownError{};
        }
    }
}