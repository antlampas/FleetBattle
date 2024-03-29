/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef PLAYERBOARD_HPP
#define PLAYERBOARD_HPP

#include "types.hpp"
#include "board.hpp"
#include "ships.hpp"

#ifdef TESTPLAYERBOARD
#define private public
#endif

namespace fleetBattle
{
    namespace playerBoard
    {

        class playerBoard final : public board
        {
            private:
            deployedShips_t        deployedShips {};
            board_t                shipsLayer    {};
            private:
            board_t                applyShipsLayer();
            protected:
            virtual bool           hit(coordinates_t)                            override final;
            public:
            playerBoard(deployedShips_t);
            playerBoard()                                                        = delete;
            virtual board_t        getBoardStatus()                              override final;
            virtual squareStatus_t getSquareStatus(coordinates_t)                override final;
            virtual bool           isSquareAlreadyHit(coordinates_t)             override final;
            virtual shootStatus_t  shoot(coordinates_t)                          override final;
            virtual squareStatus_t setSquareStatus(coordinates_t,squareStatus_t) override final;
        };
    }
}
#endif