/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

char playerBoard::setSquareStatus(coordinates_t c,squareStatus_t s)
{
    try
    {
        decodedCoordinatesPair_t coordinates {this->decodeCoordinates(c)};

        this->Board.at(coordinates.first).at(coordinates.second) = s;
        
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