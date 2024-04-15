/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>
#include <future>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::chrono_literals;

#include "types.hpp"
#include "exceptions.hpp"
#include "playerBoard.hpp"
#include "opponentBoard.hpp"
#include "agent.hpp"

#ifdef TESTPLAYER
#define private public
#endif

namespace fleetBattle
{
    class player final
    {
        private:
        friend class matchMaster;
        friend class game;
        
        private:
        std::shared_ptr<playerBoard>   ownBoard;
        std::shared_ptr<opponentBoard> otherBoard;
        std::shared_ptr<command_t>     command;
        std::shared_ptr<std::mutex>    mutex;
        
        private:
        board_t        checkOwnBoard();
        board_t        checkOpponentBoard();
        squareStatus_t setSquareStatus(coordinates_t,squareStatus_t);
        squareStatus_t getSquareStatus(coordinates_t);
        
        public:
        player()                                 = delete;
        player( std::shared_ptr<playerBoard>,
                std::shared_ptr<opponentBoard>,
                std::shared_ptr<command_t>,
                std::shared_ptr<std::mutex>
              );
        shootStatus_t  shoot(coordinates_t);
    };
}
#endif