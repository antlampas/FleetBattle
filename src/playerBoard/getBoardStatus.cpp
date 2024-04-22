/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

namespace fleetBattle
{
    board_t playerBoard::_getBoardStatus()
    {
        board_t b {this->applyShipsLayer()};
        
        return b;
    }
    board_t playerBoard::getBoardStatus()
    {
        return this->_getBoardStatus();
    }
}