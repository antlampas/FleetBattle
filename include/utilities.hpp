/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

namespace fleetBattle
{
    bool                     isCoordinatesValid(coordinates_t);
    decodedCoordinatesPair_t decodeCoordinates(coordinates_t);
    bool                     isShipHorizontal(shipPosition_t);
    bool                     isShipHVertical(shipPosition_t);
    bool                     isShipOverlapping(shipPosition_t,shipPosition_t);
    bool                     isInlineShipsOverlapping(decodedCoordinateSingle_t,decodedCoordinateSingle_t,decodedCoordinateSingle_t,decodedCoordinateSingle_t);
    bool                     isCrossingShipsOverlapping(decodedCoordinatesPair_t,decodedCoordinatesPair_t,decodedCoordinatesPair_t,decodedCoordinatesPair_t);
}

#endif