/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

namespace fleetBattle
{
    bool playerBoard::drawDeployedShipsOnBoard()
    {
        try
        {
            for(auto deployedShip: this->deployedShips)
            {
                int min = 0,max = 0;
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
                return true;
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