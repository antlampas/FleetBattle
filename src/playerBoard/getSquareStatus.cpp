/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

namespace fleetBattle
{
    squareStatus_t playerBoard::getSquareStatus(coordinates_t c)
    {
        try
        {
            decodedCoordinatesPair_t coordinates {decodeCoordinates(c)};
            if(coordinates != std::pair<unsigned char,unsigned char>(-1,-1))
            {
                board_t b {this->applyShipsLayer()};
                
                return b.at(coordinates.first).at(coordinates.second);
            }
            
            return 'U';
        }
        catch(coordinatesNotValid& e)
        {
            throw;
        }
        catch(...)
        {
            throw unknownError{};
        }
    }
}