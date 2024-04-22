/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

#include <regex>

namespace fleetBattle
{
    bool playerBoard::isSquareAlreadyHit(coordinates_t c)
    {
        try
        {
            decodedCoordinatesPair_t coordinates {decodeCoordinates(c)};
            if(coordinates != std::pair<unsigned char,unsigned char>(-1,-1))
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
        catch(coordinatesNotValid& e)
        {
            throw e;
        }
        catch(...)
        {
            throw unknownError{};
        }
    }
}