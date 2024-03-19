/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "board.hpp"

#include <iostream>

board::board() : Board({})
{
    for(auto row: {0,1,2,3,4,5,6,7,8,9})
        this->Board.push_back(std::vector<squareStatus_t>(10,'W'));

    for(auto row: {0,1,2,3,4,5,6,7,8,9}){
        for(auto column: {0,1,2,3,4,5,6,7,8,9})
            std::cout << this->Board.at(row).at(column) << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

board::~board(){}