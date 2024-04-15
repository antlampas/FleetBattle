/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef GAME_HPP
#define GAME_HPP

#include "types.hpp"
#include "exceptions.hpp"
#include "board.hpp"
#include "matchMaster.hpp"
#include "player.hpp"

#ifdef TESTGAME
#define private public
#endif

namespace fleetBattle
{
    class game final
    {
        private:
        std::shared_ptr<player> playerA;
        std::shared_ptr<player> playerB;
        std::thread             agentA;
        std::thread             agentB;
        std::thread             mm;
        /* std::shared_ptr<agent>       agentA;
        std::shared_ptr<agent>       agentB;
        std::shared_ptr<matchMaster> mm; */
        
        public:
        game() = delete;
        game(   std::shared_ptr<command_t>,
                std::shared_ptr<std::mutex>,
                std::shared_ptr<std::mutex>,
                deployedShips_t,
                deployedShips_t
            );
        ~game();
        bool operator()();
    };
}
#endif