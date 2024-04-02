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
        std::lock_guard<std::mutex>(*(this->mutex));
        
        std::thread runAgent(*this->agentInput());
        
        runAgent.join();
        
        return true;
    }
}