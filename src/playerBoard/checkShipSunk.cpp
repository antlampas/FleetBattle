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

        int i=0;
        bool shipHit = false;
        for(auto deployedShip: this->deployedShipsMap)
        {
            for(auto square: deployedShip)
            {
                if(coordinates == square)
                {
                    shipHit = true;
                    break;
                }
            }
            if(shipHit)
            {
                for(auto square=deployedShip.begin();;square++)
                {
                    squareStatus_t shipSquare = this->getSquareStatus(*square);
                    if(shipSquare != 's')
                        break;
                    else
                        if(square==deployedShip.end())
                            this->destroyedShips.at(i) = true;
                }
                
                return;
            }
        i++;
        }
        return;
    }
}