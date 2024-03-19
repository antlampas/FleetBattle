/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

board_t playerBoard::applyShipsLayer()
{
    board_t b {this->Board};
    
    for(auto row: {0,1,2,3,4,5,6,7,8,9})
        for(auto column: {0,1,2,3,4,5,6,7,8,9})
            if(this->shipsLayer.at(row).at(column) != 'U')
                b.at(row).at(column) = this->shipsLayer.at(row).at(column);
    return b;
}