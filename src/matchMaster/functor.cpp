/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "matchMaster.hpp"

#include <cstdlib>

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
                std::this_thread::sleep_for(1ms);
                lockA.lock();
                if(this->command->first == "shoot" && this->command->second != "")
                {
                    squareStatus_t status = this->playerBoardB->shoot(this->command->second);
                    this->opponentBoardA->setSquareStatus(this->command->second,status);
                }
                else if(this->command->first == "exit" || this->command->first == "quit")
                {
                    break;
                }
                else
                {
                    std::this_thread::sleep_for(1ms);
                    continue;
                }
                std::this_thread::sleep_for(1ms);
                this->playerInTurn = 'B';
            }
            else if(this->playerInTurn == 'B')
            {
                lockB.unlock();
                std::this_thread::sleep_for(1ms);
                lockB.lock();
                
                if(this->command->first == "shoot" && this->command->second != "")
                {
                    squareStatus_t status = this->playerBoardA->shoot(this->command->second);
                    this->opponentBoardB->setSquareStatus(this->command->second,status);
                }
                else if(this->command->first == "exit" || this->command->first == "quit")
                {
                    std::exit(0);
                }
                else
                {
                    std::this_thread::sleep_for(1ms);
                    continue;
                }
                std::this_thread::sleep_for(1ms);
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