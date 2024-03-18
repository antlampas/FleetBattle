/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

playerBoard::playerBoard(deployedShips_t deployedShips)
{
    for(auto ship: deployedShips)
    {
        std::string shipName = ship.first;
        std::pair<std::string,std::string> shipCoordinates = ship.second;
        std::pair<decodedCoordinatesPair_t,decodedCoordinatesPair_t> decodedShipCoordinates {};
        decodedShipCoordinates.first  = this->decodeCoordinates(shipCoordinates.first);
        decodedShipCoordinates.second = this->decodeCoordinates(shipCoordinates.second);
        bool isOnSameRow              = (decodedShipCoordinates.first.first == decodedShipCoordinates.second.first);
        bool isOnSameColumn           = (decodedShipCoordinates.first.second == decodedShipCoordinates.second.second);
        bool isVerticalOrHorizontal   = !(isOnSameRow && isOnSameColumn) && (isOnSameRow || isOnSameColumn);

        if(((decodedShipCoordinates.first != std::pair<int,int>(-1,-1)) || (decodedShipCoordinates.second != std::pair<int,int>(-1,-1))) && isVerticalOrHorizontal)
            this->deployedShips.insert(std::pair<std::string,std::pair<std::string,std::string>>(shipName,shipCoordinates));
        else
            throw shipNotValid{};
    }
}

playerBoard::playerBoard(){}