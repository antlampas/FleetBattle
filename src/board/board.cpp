/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "board.hpp"

#include <iostream>

board::board() : Board({board_t(10,std::vector<squareStatus_t>(10,'W'))}){}
board::~board(){}