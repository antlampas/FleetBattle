/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

#include <iostream>

playerBoard::playerBoard(deployedShips_t deployedShips) : shipsLayer({{'U'}})
{

    for(auto ship: deployedShips)
    {
        std::pair<decodedCoordinatesPair_t,decodedCoordinatesPair_t> decodedShipCoordinates {};
        try
        {
            decodedShipCoordinates.first  = this->decodeCoordinates(ship.first);
            decodedShipCoordinates.second = this->decodeCoordinates(ship.second);
        }
        catch(coordinatesNotValid)
        {
            throw;
        }
        catch(...)
        {
            throw unknownError{};
        }
        bool isOnSameRow              = (decodedShipCoordinates.first.first  == decodedShipCoordinates.second.first);
        bool isOnSameColumn           = (decodedShipCoordinates.first.second == decodedShipCoordinates.second.second);
        bool isVerticalOrHorizontal   = !(isOnSameRow && isOnSameColumn) && (isOnSameRow || isOnSameColumn);

        if(isVerticalOrHorizontal)
            this->deployedShips.push_back(ship);
        else
            throw shipNotValid{};
    }
    for(auto deployedShip: this->deployedShips)
    {
        int min = 0,max = 0;
        try
        {
            const int& startRow    = this->decodeCoordinates(deployedShip.first).first;
            const int& endRow      = this->decodeCoordinates(deployedShip.second).first;
            const int& startColumn = this->decodeCoordinates(deployedShip.first).second;
            const int& endColumn   = this->decodeCoordinates(deployedShip.second).second;
            if(startRow == endRow)
            {
                const int& row = startRow;

                if(startColumn < endColumn)
                {
                    min = startColumn;
                    max = endColumn;
                }else{
                    min = endColumn;
                    max = startColumn;
                }

                for(int i=min;i<=max;i++)
                    this->shipsLayer.at(row).at(i) = 'S';
            }
            else if(startColumn == endColumn)
            {
                const int& column = startColumn;

                if(startRow < endRow)
                {
                    min = startRow;
                    max = endRow;
                }else{
                    min = endRow;
                    max = startRow;
                }

                for(int i=min;i<=max;i++)
                    this->shipsLayer.at(i).at(column) = 'S';
            }
        }
        catch(coordinatesNotValid)
        {
            throw;
        }
        catch(...)
        {
            throw unknownError{};
        }
    }
}