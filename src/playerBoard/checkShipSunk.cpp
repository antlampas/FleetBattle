/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"
#include <regex>

namespace fleetBattle
{
    void playerBoard::checkShipSunk(coordinates_t coordinates)
    {
        std::regex c {"^[a-zA-Z]"};
        std::regex r {"[1-9]$|10$"};

        decodedCoordinatesPair_t decodedCoordinates = decodeCoordinates(coordinates);
        std::array<std::array<std::string,5>,5> deployedShipsMap {};

        int j=0;
        for(auto deployedShip: this->deployedShips)
        {
            if(isShipHorizontal(deployedShip))
            {
                char column1 = std::regex_match(deployedShip.first,c);
                char column2 = std::regex_match(deployedShip.second,c);
                char row     = std::regex_match(deployedShip.first,r);
                for(char coord=column1,int i=0;coord<=column2;coord++,i++)
                    deployedShipsMap.at(j).at(i) = std::string(coord+row);
            }
            if(isShipVertical(deployedShip))
            {
                char row1   = std::regex_match(deployedShip.first,r);
                char row2   = std::regex_match(deployedShip.second,r);
                char column = std::regex_match(deployedShip.first,c);
                for(char coord=row1,int i=0;coord<=row2;coord++,i++)
                    deployedShipsMap.at(j).at(i) = std::string(col+coord);
            }
        }
    }
}