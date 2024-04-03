/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "player.hpp"

namespace fleetBattle
{
    bool player::operator()()
    {
        std::packaged_task<void()> agent(std::bind(&player::user,this));
        std::thread agentThread(std::move(agent));
        
        agentThread.join();
        
        return true;
    }
}