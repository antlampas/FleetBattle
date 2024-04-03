/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "agent.hpp"

namespace fleetBattle
{
    void agent::getOpponentBoard(board_t board)
    {
        for(auto row: board)
        {
            for(auto column: row)
            {
                short i = 0;
                
                if(i < 9)
                    std::cout << column << " ";
                else
                    std::cout << column;
                i++;
            }
            std::cout << std::endl;
        }
    }
}