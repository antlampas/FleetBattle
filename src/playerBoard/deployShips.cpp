/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

namespace fleetBattle
{
    bool deployShips(deployedShips_t deployedShips)
    {
        int i = 0;
        for(auto ship: deployedShips)
        {
            bool isVertical             {isShipVertical(ship)}
            bool isHorizontal           {isShipHorizontal(ship)}
            bool isVerticalOrHorizontal {(isVertical || isHorizontal) && !(isVertical && isHorizontal)};

            if(isVerticalOrHorizontal)
            {
                this->deployedShips.at(i) = ship;
            }
            else
            {
                throw shipNotValid{};
            }

            for(auto deployedShip: this->deployedShips)
            {
                if(isVertical)
                {
                    for(auto row=deployedShip.first.at(1),int j=0;row<=deployedShip.second.at(1);row++,j++)
                    {
                        this->deployedShipsMap.at(i).at(j) = std::string(deployedShip.first.at(0)+row);
                    }
                }
                else if(isHorizontal)
                {
                    for(auto column=deployedShip.first.at(0),int j=0;column<=deployedShip.second.at(0);column++,j++)
                    {
                        this->deployedShipsMap.at(i).at(j) = std::string(column+deployedShip.first.at(1));
                    }
                }
            }
            i++;
        }
        return true;
    }
}