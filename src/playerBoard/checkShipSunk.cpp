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
        bool shipSunk = false;
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
                for(auto square=deployedShip.begin();;std::advance(square))
                {
                    std::regex shipSquareHit("[s]");
                    squareStatus_t shipSquare = this->getSquareStatus(square);
                    if(!std::regex_match(shipSquare,shipSquareHit))
                        break;
                    else
                        if(square==deployedShip.end())
                            this->destroyedShip.at(i) = true;
                }
                return;
            }
        i++;
        }
        return;
    }
}