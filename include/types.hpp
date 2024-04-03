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

    using decodedCoordinateSingle_t = unsigned char;
    using decodedCoordinatesPair_t  = std::pair<decodedCoordinateSingle_t,decodedCoordinateSingle_t>;
    using shipSize_t                = unsigned char;
    using shipsList_t               = std::map<std::string,unsigned char>;
    using squareStatus_t            = char;
    using playerInTurn_t            = char;
    using shipsSquaresList_t        = std::array<std::array<squareStatus_t,10>,10>;
    using command_t                 = std::pair<std::string,std::string>;
    using coordinates_t             = std::string;
    using shootStatus_t             = unsigned char;
    using board_t                   = std::array<std::array<squareStatus_t,10>,10>;
    using shipStatus_t              = std::array<squareStatus_t,10>;
    using deployedShips_t           = std::array<std::pair<std::string,std::string>,5>;
    using destroyedShips_t          = std::array<bool,5>;
}
#endif