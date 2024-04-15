/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "agent.hpp"

namespace fleetBattle
{
    agent::agent(   playerInTurn_t              p,
                    const playerInTurn_t&       pit,
                    std::shared_ptr<std::mutex> mtx,
                    std::shared_ptr<command_t>  cmd) :  standalone(false),
                                                        playerInTurn(pit),
                                                        mutex(mtx),
                                                        command(cmd),
                                                        player(p)
    {}
    agent::~agent()
    {
        this->standalone = false;
    }
}