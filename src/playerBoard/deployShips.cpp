/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"



namespace fleetBattle
{
    bool playerBoard::deployShips(deployedShips_t deployedShips)
    {
        int i = 0;
        
        for(auto ship: deployedShips)
        {
            if(ship.first.size() == 0) break;
            
            bool isVertical             {isShipVertical(ship)};
            bool isHorizontal           {isShipHorizontal(ship)};
            bool isVerticalOrHorizontal {(isVertical || isHorizontal) && !(isVertical && isHorizontal)};
            
            if(isVerticalOrHorizontal)
            {
                this->deployedShips.at(i) = ship;
            }
            else
            {
                throw shipNotValid{};
            }
            if(isVertical)
            {
                for(struct {char row;int j;} s ={ship.first.at(1),0};s.row<=ship.second.at(1);s.row++,s.j++)
                {
                    this->deployedShipsMap.at(i).at(s.j) = std::string(ship.first.at(0),1).append(s.row,1);
                }
            }
            else if(isHorizontal)
            {
                for(struct {char column;int j;} s = {ship.first.at(0),0};s.column<=ship.second.at(0);s.column++,s.j++)
                {
                    this->deployedShipsMap.at(i).at(s.j) = std::string(s.column,1).append(ship.first.at(1),1);
                }
            }
            i++;
        }
        return true;
    }
}