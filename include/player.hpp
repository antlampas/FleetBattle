/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>
#include <mutex>

#include "types.hpp"
#include "board.hpp"

#ifdef TESTPLAYER
#define private public
#endif

namespace fleetBattle
{
    namespace player
    {

        class player final
        {
            private:
            ::std::shared_ptr<playerBoard::playerBoard>   ownBoard;
            ::std::shared_ptr<playerBoard::opponentBoard> otherBoard;
            ::std::shared_ptr<command_t>                  command;
            ::std::shared_ptr<::std::mutex>                 mutex;
            
            private:
            board_t        checkOwnBoard();
            board_t        checkOpponentBoard();
            shootStatus_t  shoot(coordinates_t);
            squareStatus_t setSquareStatus(coordinates_t,squareStatus_t);
            squareStatus_t getSquareStatus(coordinates_t);
            
            public:
            player()                                                                                                                    = delete;
            player(::std::shared_ptr<playerBoard>,::std::shared_ptr<opponentBoard>,::std::shared_ptr<command_t>,::std::shared_ptr<::std::mutex>);
            bool getCommand(::std::string);
            int operator()();
        };
    }
}
#endif