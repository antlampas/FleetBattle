/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <vector>
#include <utility>
#include <string>
#include <map>

#include "types.hpp"
#include "exceptions.hpp"

#ifdef TESTBOARD
#define private public
#endif

namespace fleetBattle
{
    class board
    {
        /*
        * U = unknown
        * S = ship square
        * W = water
        * s = ship square hit
        * w = water square hit
        */
        protected:
        board_t Board;
        protected:
        virtual bool             hit(coordinates_t)                            = 0; 
        public:
        enum shootReturnCodes    {HIT,MISSED,SQUARE_ALREADY_HIT};
        public:
        board();
        virtual ~board();
        virtual board_t          getBoardStatus()                              = 0;
        virtual squareStatus_t   getSquareStatus(coordinates_t)                = 0;
        virtual bool             isSquareAlreadyHit(coordinates_t)             = 0;
        virtual shootStatus_t    shoot(coordinates_t)                          = 0;
        virtual squareStatus_t   setSquareStatus(coordinates_t,squareStatus_t) = 0;
    };
}
#endif