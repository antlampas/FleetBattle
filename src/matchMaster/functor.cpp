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
            if(this->playerInTurn == 'A')
            {
                    lockA.unlock();
                    (*this->playerA)();
                    lockA.lock();
                    if(this->command->first == "shoot")
                    {
                        squareStatus_t status = this->playerBoardB->shoot(this->command->second);
                        this->playerA->otherBoard->setSquareStatus(this->command->second,status);
                    }
                    this->playerInTurn = 'B';
            }
            else if(this->playerInTurn == 'B')
            {
                    lockB.unlock();
                    (*this->playerB)();
                    lockB.lock();
                    if(this->command->first == "shoot")
                    {
                        squareStatus_t status = this->playerBoardA->shoot(this->command->second);
                        this->playerB->otherBoard->setSquareStatus(this->command->second,status);
                    }
                    this->playerInTurn = 'A';
            }
            else
            {
                    this->playerInTurn = 'A';
            }
            std::this_thread::sleep_for(1ms);
        }

        return true;
    }
}