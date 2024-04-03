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
        std::packaged_task<void()> match(*(this->mm));
        std::thread matchThread(std::move(match));
        
        matchThread.join();
        
        return true;
    }
 }