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
    }
    catch(coordinatesNotValid)
    {
        throw;
    }
    catch(...)
    {
        throw unknownError{};
    }

    return 'a';
}