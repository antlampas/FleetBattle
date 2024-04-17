/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>
#include <array>
#include <map>
#include <utility>
#include <vector>

namespace fleetBattle
{
    using decodedCoordinateSingle_t = unsigned char; //Row OR column
    using decodedCoordinatesPair_t  = std::pair<decodedCoordinateSingle_t,decodedCoordinateSingle_t>; //Decoded row AND column
    using shipSize_t                = unsigned char;
    using shipsList_t               = std::array<unsigned char,5>; //Ships types list, for a maximum of 5 different types, with 8-bit dimention
    using squareStatus_t            = unsigned char;
    using playerInTurn_t            = unsigned char;
    using shipsSquaresList_t        = std::array<std::array<squareStatus_t,10>,10>;
    using command_t                 = std::pair<std::string,std::string>;
    using coordinates_t             = std::string; //Standard-format, i.e. RowColumn format e.g. "A1", "C5"
    using shootStatus_t             = unsigned char; //Ship hit; ship missed; square already hit
    using board_t                   = std::array<std::array<squareStatus_t,10>,10>; //Classic 10x10 Fleet Battle board
    using shipStatus_t              = std::array<squareStatus_t,10>;
    using deployedShips_t           = std::array<std::pair<std::string,std::string>,5>; //a maximum of 5 ships; a pair of coordinates: beginning and end of the ship
    using destroyedShips_t          = std::array<bool,5>;
}
#endif