/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

shootStatus_t playerBoard::shoot(coordinates_t c)
{
    try
    {
        decodedCoordinatesPair_t coordinates {this->decodeCoordinates(c)};
    }
    catch(coordinatesNotValid& e)
    {
        throw e;
    }
    catch(...)
    {
        throw unknownError()
    }
    
    std::regex alreadyHit {"[ws]"};

    if(!std::regex_match(std::string(1,this->getSquareStatus(c)),alreadyHit))
        if(this->hit(c))
            return this->returnCodes.HIT;
        else
            return this->returnCodes.MISSED;
    else return this->returnCodes.SQUARE_ALREADY_HIT;
}