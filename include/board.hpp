/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <vector>
#include <utility>
#include <string>

using coordinates_t             = std::string;
using decodedCoordinateSingle_t = char;
using decodedCoordinatePair_t   = std::pair<decodedCoordinateSingle_t,decodedCoordinateSingle_t>;
using squareStatus_t            = char;
using board_t                   = std::vector<std::vector<squareStatus_t>>;
using shipSize_t                = char;
using shipStatus_t              = std::vector<squareStatus_t>;
using deployedShips_t           = std::vector<std::pair<shipSize_t&,shipStatus_t>>;
using destroyedShips_t          = std::vector<shipSize_t&>;

/*
 * U = unknown
 * O = square occupied
 * W = water
 * o = ship square hit
 * w = water square hit
 */

class board
{
    protected:
    board_t board {};
    virtual bool hit(decodedCoordinatePair_t)             = 0; 
    
    private:
    bool isCoordinateValid(coordinates_t);
    decodedCoordinatePair_t decodedCoordinates(coordinates_t);

    public:
    virtual board_t getBoardStatus()                      = 0;
    virtual squareStatus_t getSquareStatus(coordinates_t) = 0;
    virtual bool isSquareAlreadyHit(coordinates_t)        = 0;
    virtual bool shoot(coordinates_t)                     = 0;
    virtual char squareStatus(coordinates_t)              = 0;
};