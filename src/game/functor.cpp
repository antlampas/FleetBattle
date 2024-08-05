/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "game.hpp"

#include <functional>
#include <chrono>

namespace fleetBattle
{
   bool game::operator()()
   {
       std::packaged_task<void()> match(*this->mm);
       std::packaged_task<bool()> agentA(*this->agentA);
       std::packaged_task<bool()> agentB(*this->agentB);

       std::thread matchThread(std::move(match));
       std::this_thread::sleep_for(std::chrono::milliseconds(100));
       std::thread agentAThread(std::move(agentA));
       std::this_thread::sleep_for(std::chrono::milliseconds(100));
       std::thread agentBThread(std::move(agentB));

       matchThread.join();
       agentAThread.join();
       agentBThread.join();

       return true;
   }
}