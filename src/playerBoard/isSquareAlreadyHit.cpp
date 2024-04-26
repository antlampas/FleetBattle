/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

#include <regex>

#include <iostream>

namespace fleetBattle
{
    bool playerBoard::isSquareAlreadyHit(coordinates_t c)
    {
        std::cout << "a" << std::endl;
        decodedCoordinatesPair_t coordinates {decodeCoordinates(c)};
        std::cout << "b" << std::endl;
        if(coordinates != std::pair<unsigned char,unsigned char>(-1,-1))
        {
            std::cout << "c" << std::endl;
            std::regex alreadyHit {"[ws]"};
            board_t b {this->applyShipsLayer()};
            std::cout << "d" << std::endl;
            if(std::regex_match(std::string(1,b.at(coordinates.first).at(coordinates.second)),alreadyHit))
            {
                std::cout << "e" << std::endl;
                return true;
            }
            else
            {
                std::cout << "f" << std::endl;
                return false;
            }
        }
        return false;
    }
}