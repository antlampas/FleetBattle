/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "matchMaster.hpp"

namespace fleetBattle
{
    bool matchMaster::operator()()
    {
        std::unique_lock<std::mutex> lockA(*this->mutexA,std::defer_lock);
        std::unique_lock<std::mutex> lockB(*this->mutexB,std::defer_lock);

        std::lock(lockA,lockB);

        while(true)
        {
            switch(this->playerInTurn)
            {
                case 'A':
                    lockA.unlock();
                    (*this->playerA)();
                    lockA.lock();
                    if(this->command->first == "shoot")
                    {
                        this->playerBoardB->shoot(this->command->first,this->command->second)
                    }
                    this->playerInTurn = 'B';
                    break;
                case 'B':
                    lockB.unlock();
                    (*this->playerB)();
                    lockB.lock();
                    if(this->command->first == "shoot")
                    {
                        this->playerBoardA->shoot(this->command->first,this->command->second)
                    }
                    this->playerInTurn = 'A';
                    break;
                default:
                    this->playerInTurn = 'A';
            }
            std::this_thread::sleep_for(1ms);
        }

        return true;
    }
}