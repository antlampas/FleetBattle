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
        std::shared_ptr<playerBoard>   ownBoard;
        std::shared_ptr<opponentBoard> otherBoard;
        
        public:
        player()                                 = delete;
        player( std::shared_ptr<playerBoard>,
                std::shared_ptr<opponentBoard>,
                std::shared_ptr<command_t>,
                std::shared_ptr<std::mutex>
              );
        board_t        getOwnBoard();
        board_t        getOpponentBoard();
        squareStatus_t setOwnBoardSquareStatus(coordinates_t,squareStatus_t);
        squareStatus_t getOwnBoardSquareStatus(coordinates_t);
        squareStatus_t setOtherBoardSquareStatus(coordinates_t,squareStatus_t);
        squareStatus_t getOtherBoardSquareStatus(coordinates_t);
        shootStatus_t  shoot(coordinates_t);
    };
}
#endif