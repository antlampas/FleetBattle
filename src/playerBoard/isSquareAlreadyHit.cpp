/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

#include <regex>

bool playerBoard::isSquareAlreadyHit(coordinates_t c)
{
    decodedCoordinatesPair_t coordinates = this->decodeCoordinates(c);
    if(coordinates != std::pair<int,int>(-1,-1))
    {
        std::regex alreadyHit {"[ws]"};
        board_t b {this->applyShipsLayer()};
        if(std::regex_match(std::string(1,b.at(coordinates.first).at(coordinates.second)),alreadyHit))
            return true;
        else
            return false;
    }
    return false;
}