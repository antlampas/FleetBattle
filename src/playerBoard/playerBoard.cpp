/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

namespace fleetBattle
{
    playerBoard::playerBoard(deployedShips_t deployedShips)
    {
        for(auto firstShip = deployedShips.begin();firstShip != std::prev(deployedShips.end());std::advance(firstShip))
        {
            for(auto secondShip = std::next(deployedShips.begin());firstShip != deployedShips.end();std::advance(secondShip))
        }

        for(auto row: {0,1,2,3,4,5,6,7,8,9})
            for(auto column: {0,1,2,3,4,5,6,7,8,9})
                shipsLayer.at(row).at(column) = 'U';
        
        for(auto ship: this->destroyedShips)
            ship = false;
        
        int i = 0;
        for(auto ship: deployedShips)
        {
            std::pair<decodedCoordinatesPair_t,decodedCoordinatesPair_t> decodedShipCoordinates {};
            try
            {
                decodedShipCoordinates.first  = decodeCoordinates(ship.first);
                decodedShipCoordinates.second = decodeCoordinates(ship.second);
            }
            catch(coordinatesNotValid)
            {
                throw;
            }
            catch(...)
            {
                throw unknownError{};
            }
            bool isOnSameRow            = (decodedShipCoordinates.first.first  == decodedShipCoordinates.second.first);
            bool isOnSameColumn         = (decodedShipCoordinates.first.second == decodedShipCoordinates.second.second);
            bool isVerticalOrHorizontal = !(isOnSameRow && isOnSameColumn) && (isOnSameRow || isOnSameColumn);

            if(isVerticalOrHorizontal)
            {
                this->deployedShips.at(i) = ship;
                i++;
            }
            else
            {
                throw shipNotValid{};
            }
        }
        for(auto deployedShip: this->deployedShips)
        {
            int min = 0,max = 0;
            try
            {
                const int& startRow    = decodeCoordinates(deployedShip.first).first;
                const int& endRow      = decodeCoordinates(deployedShip.second).first;
                const int& startColumn = decodeCoordinates(deployedShip.first).second;
                const int& endColumn   = decodeCoordinates(deployedShip.second).second;
                
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
}