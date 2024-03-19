/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "board.hpp"

#include <regex>
#include <cctype>

decodedCoordinatesPair_t board::decodeCoordinates(coordinates_t coordinates)
{
    decodedCoordinatesPair_t decodedCoordinates {};
    
    std::transform(coordinates.begin(), coordinates.end(), coordinates.begin(), [](unsigned char c){ return std::tolower(c); });
    
    if(this->isCoordinatesValid(coordinates)) decodedCoordinates = decodedCoordinatesPair_t{(int)coordinates.at(0) - 97,std::stoi(coordinates,(std::size_t*)1)};
    else                                      decodedCoordinates = decodedCoordinatesPair_t{-1,-1};

    return decodedCoordinates;
}