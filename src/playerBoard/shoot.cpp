/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

#include <regex>

namespace fleetBattle
{
    shootStatus_t playerBoard::shoot(coordinates_t c)
    {
        try
        {
            decodedCoordinatesPair_t coordinates {this->decodeCoordinates(c)};

            std::regex stillNotHit {"[WS]"};

            if(std::regex_match(std::string(1,this->getSquareStatus(c)),stillNotHit))
            {
                if(this->hit(c))
                {
                    this->shipsLayer.at(coordinates.first).at(coordinates.second) = 's';
                    this->setSquareStatus(c,'s');
                    this->checkShipSunk(c);
                }
                else
                {
                    this->setSquareStatus(c,'w');
                }
                return this->getSquareStatus(c);
            }
            else
            {
                return this->getSquareStatus(c);
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
}