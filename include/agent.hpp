/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef AGENT_HPP
#define AGENT_HPP

#include <memory>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std::chrono_literals;

#include "types.hpp"

 namespace fleetBattle
 {
    class agent final
    {
        private:
        bool                            standalone;
        playerInTurn_t                  player;
        std::unique_ptr<playerInTurn_t> playerInTurn;
        std::shared_ptr<std::mutex>     mutex;
        std::shared_ptr<command_t>      command;

        public:
        agent(playerInTurn_t,std::unique_ptr<playerInTurn_t>,std::shared_ptr<std::mutex>,std::shared_ptr<command_t>);
        ~agent();
        void getOwnBoard(board_t);
        void getOpponentBoard(board_t);
        bool operator()();
    };
 }

 #endif