/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef OPPONENTBOARD_HPP
#define OPPONENTBOARD_HPP

#include "board.hpp"

#ifdef TESTOPPONENTBOARD
#define private public
#endif

class opponentBoard : public board
{
    private:
    virtual bool hit(decodedCoordinatesPair_t)             = 0; 
    public:
    virtual board_t getBoardStatus()                      = 0;
    virtual squareStatus_t getSquareStatus(coordinates_t) = 0;
    virtual bool isSquareAlreadyHit(coordinates_t)        = 0;
    virtual bool shoot(coordinates_t)                     = 0;
    virtual char squareStatus(coordinates_t)              = 0;
};

#endif