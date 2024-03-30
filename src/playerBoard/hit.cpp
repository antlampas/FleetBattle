/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

namespace fleetBattle
{
    bool playerBoard::hit(coordinates_t c)
    {
        try
        {
            decodedCoordinatesPair_t coordinates {this->decodeCoordinates(c)};

            if(this->shipsLayer.at(coordinates.first).at(coordinates.second) == 'S')
            {
                this->shipsLayer.at(coordinates.first).at(coordinates.second) = 's';
                this->setSquareStatus(c,'s');
                return true;
            }
            else
                return false;
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