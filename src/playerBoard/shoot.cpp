/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

#include <regex>

shootStatus_t playerBoard::shoot(coordinates_t c)
{
    try
    {
        decodedCoordinatesPair_t coordinates {this->decodeCoordinates(c)};
        
        std::regex alreadyHit {"[ws]"};

        if(!std::regex_match(std::string(1,this->getSquareStatus(c)),alreadyHit))
            if(this->hit(c)){
                returnCodes code = HIT;
                return this->HIT;
            }
            else
            {
                returnCodes code = MISSED;
                return this->MISSED;
            }
        else
        {
            returnCodes code = SQUARE_ALREADY_HIT;
            return this->SQUARE_ALREADY_HIT;
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