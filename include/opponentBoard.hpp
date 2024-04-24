/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef OPPONENTBOARD_HPP
#define OPPONENTBOARD_HPP

#include "types.hpp"
#include "exceptions.hpp"
#include "board.hpp"

#include <spdlog/spdlog.h>

#ifdef TESTOPPONENTBOARD
#define private public
#endif

namespace fleetBattle
{
    class opponentBoard final : public board
    {
        protected:
        virtual bool           hit(coordinates_t)                            override final;
        virtual board_t        _getBoardStatus()                             override final;
        public:
        opponentBoard();
        virtual squareStatus_t getSquareStatus(coordinates_t)                override final;
        virtual bool           isSquareAlreadyHit(coordinates_t)             override final; 
        virtual squareStatus_t setSquareStatus(coordinates_t,squareStatus_t) override final;

        public:
        board_t getBoardStatus();
    };
}
#endif