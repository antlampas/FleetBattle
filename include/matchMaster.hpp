/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef MATCHMASTER_HPP
#define MATCHMASTER_HPP

#include <memory>
#include <mutex>

#include "types.hpp"
#include "exceptions.hpp"
#include "playerBoard.hpp"
#include "opponentBoard.hpp"

#ifdef TESTMATCHMASTER
#define private public
#endif

namespace fleetBattle
{
    namespace matchMaster
    {
        class matchMaster final
        {
            private:
            std::pair<playerInTurn_t,shipsSquaresList_t> ships;
            std::unique_ptr<playerBoard::playerBoard>    playerBoardA;
            std::unique_ptr<playerBoard::playerBoard>    playerBoardB;
            std::shared_ptr<command_t>                   command;
            playerInTurn_t                               playerInTurn;
            std::shared_ptr<std::mutex>                  mutex;

            private:
            bool isShipSunk();

            public:
            matchMaster() = delete;
            matchMaster(std::unique_ptr<playerBoard::playerBoard>,
                        std::unique_ptr<playerBoard::playerBoard>,
                        std::shared_ptr<command_t>,
                        playerInTurn_t
                       );
            int operator()();
        };
    }
}
#endif