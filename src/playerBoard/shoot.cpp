/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

#include <regex>

namespace fleetBattle
{
    namespace playerBoard
    {
        shootStatus_t playerBoard::shoot(coordinates_t c)
        {
            try
            {
                decodedCoordinatesPair_t coordinates {this->decodeCoordinates(c)};
                
                ::std::regex stillNotHit {"[WS]"};

                if(::std::regex_match(::std::string(1,this->getSquareStatus(c)),stillNotHit))
                    if(this->hit(c))
                        return this->HIT;
                    else
                    {
                        this->setSquareStatus(c,'w');
                        return this->MISSED;
                    }
                else
                    return this->SQUARE_ALREADY_HIT;
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
}