/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

namespace fleetBattle
{
    #ifndef TYPES_HPP
    #define TYPES_HPP

    using shipSize_t                = unsigned short int;
    using shipsList_t               = std::map<std::string,unsigned short int>;
    using playerInTurn_t            = char;
    using shipsSquaresList_t        = std::array<std::array<squareStatus_t,10>,10>;
    using command_t                 = std::pair<std::string,std::string>;
    using coordinates_t             = std::string;
    using decodedCoordinateSingle_t = unsigned short int;
    using decodedCoordinatesPair_t  = std::pair<decodedCoordinateSingle_t,decodedCoordinateSingle_t>;
    using squareStatus_t            = char;
    using shootStatus_t             = unsigned short int;
    using board_t                   = std::array<std::array<squareStatus_t,10>,10>;
    using shipStatus_t              = std::array<squareStatus_t,10>;
    using deployedShips_t           = std::vector<std::pair<std::string,std::string>>;
    using destroyedShips_t          = std::vector<std::string>;
    
    #endif
}