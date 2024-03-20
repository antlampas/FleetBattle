/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

shootStatus_t playerBoard::shoot(coordinates_t c)
{
    decodedCoordinatesPair_t coordinates {this->decodeCoordinates(c)};
    
    std::regex alreadyHit {"[ws]"};
    std::regex stillNotHit {"[WS]"};

    if(coordinates != std::pair<int,int>(-1,-1))
        if(!std::regex_match(std::string(1,this->getSquareStatus(c)),alreadyHit))
            if(std::regex_match(std::string(1,this->shipsLayer.at(coordinates.first).at(coordinates.second)),stillNotHit))
                if(this->hit(c))
                    return 1;
                else
                    return 0;
            else throw squareAlreadyHit();
        else throw squareAlreadyHit();
    else throw coordinatesNotValid();
}