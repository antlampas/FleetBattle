/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "board.hpp"

#include <regex>

namespace fleetBattle
{
    bool board::isCoordinatesValid(coordinates_t coordinates)
    {
        std::regex validCoordinates {"^[a-jA-J][0-9]$|^[a-jA-J]10$"};

        return std::regex_match(coordinates,validCoordinates);
    }
}
