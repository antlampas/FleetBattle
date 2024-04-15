/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "agent.hpp"

namespace fleetBattle
{
    agent::agent(   playerInTurn_t              player,
                    playerInTurn_t&             playerInTurn,
                    std::shared_ptr<std::mutex> mutex,
                    std::shared_ptr<command_t>  command) :  playerInTurn(playerInTurn),
                                                            player(player),
                                                            mutex(mutex),
                                                            command(command),
                                                            standalone(false)
    {}
    agent::~agent()
    {
        this->standalone = false;
    }
}