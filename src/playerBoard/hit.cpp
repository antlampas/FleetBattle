/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

#include <regex>

bool playerBoard::hit(coordinates_t c)
{
    try
    {
        decodedCoordinatesPair_t coordinates {this->decodeCoordinates(c)};
        std::regex alreadyHit {"[ws]"};
        std::regex stillNotHit {"[WS]"};

        if(this->shipsLayer.at(coordinates.first).at(coordinates.second) == 'S')
        {
            this->setSquareStatus(c,'s');
            return true;
        }
        else
        {
            this->setSquareStatus(c,'w');
            return false;
        }
    }
    catch(coordinatesNotValid& e)
    {
        throw;
    }
    catch(...)
    {
        throw unknownError{};
    }
    
}