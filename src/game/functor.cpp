/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

 #include "game.hpp"

 namespace fleetBattle
 {
    bool game::operator()()
    {
        std::packaged_task<void()> match(std::move(*this->mm));
        std::packaged_task<bool()> agentA(std::move(*this->agentA));
        std::packaged_task<bool()> agentB(std::move(*this->agentB));

        std::thread matchThread(std::move(match));
        std::thread agentAThread(std::move(agentA));
        std::thread agentBThread(std::move(agentB));
        
        matchThread.join();
        agentAThread.join();
        agentBThread.join();
        
        return true;
    }
 }