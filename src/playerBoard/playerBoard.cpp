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

    for(auto deployedShip: this->deployedShips)
    {
        int min = 0,max = 0;
        const int& startRow    = this->decodeCoordinates(deployedShip.first).first;
        const int& endRow      = this->decodeCoordinates(deployedShip.second).first;
        const int& startColumn = this->decodeCoordinates(deployedShip.first).second;
        const int& endColumn   = this->decodeCoordinates(deployedShip.second).second;

        if(startRow == endRow)
        {
            const int& row = startRow;

            if(startRow < endRow)
            {
                min = startRow;
                max = endRow;
            }else{
                min = endRow;
                max = startRow;
            }

            for(int i=min;i<=max;i++)
                this->Board.at(row).at(i) = 'S';
        }
        else if(startColumn == endColumn)
        {
            const int& column = startColumn;

            if(startColumn < endColumn)
            {
                min = startColumn;
                max = endColumn;
            }else{
                min = endColumn;
                max = startColumn;
            }

            for(int i=min;i<=max;i++)
                this->Board.at(i).at(column) = 'S';
        }
    }
}