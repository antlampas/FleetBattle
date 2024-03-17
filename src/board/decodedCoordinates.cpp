/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "board.hpp"

#include <regex>
#include <cctype>

decodedCoordinatePair_t board::decodedCoordinates(coordinates_t coordinates)
{
    decodedCoordinatePair_t decodedCoordinates {};
    std::size_t* p {};
    
    std::transform(coordinates.begin(), coordinates.end(), coordinates.begin(), [](unsigned char c){ return std::tolower(c); });
    
    if(this->isCoordinatesValid(coordinates)) decodedCoordinates = decodedCoordinatePair_t{(int)coordinates.at(0) - 97,std::stoi(coordinates,++p)};
    else                                      decodedCoordinates = decodedCoordinatePair_t{-1,-1};

    return decodedCoordinates;
}