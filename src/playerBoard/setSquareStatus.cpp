/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

namespace fleetBattle
{
    squareStatus_t playerBoard::setSquareStatus(coordinates_t c,squareStatus_t s)
    {
        try
        {
            decodedCoordinatesPair_t coordinates { decodeCoordinates(c) };
            this->Board.at(coordinates.first).at(coordinates.second) = this->shipsLayer.at(coordinates.first).at(coordinates.second) = s;
            return s;
        }
        catch(coordinatesNotValid)
        {
            throw;
        }
        catch(...)
        {
            throw unknownError{};
        }
    }
}