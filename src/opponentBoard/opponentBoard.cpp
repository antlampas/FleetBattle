/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "opponentBoard.hpp"

#include <iostream>

opponentBoard::opponentBoard() : Board(std::vector<std::vector<squareStatus_t>>(10,std::vector<squareStatus_t>(10,'W')))
{
    std::cout << "OPPONENTBOARD" << std::endl;
    for(auto row: this->Board)
    {
        for(auto column: row)
            std::cout << column << " ";
        std::cout << std::endl;
    }
    std::cout << "END OPPONENTBOARD" << std::endl;
}