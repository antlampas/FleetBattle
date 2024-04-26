/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "matchMaster.hpp"

#include <cstdlib>

#include <iostream>

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
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                lockA.lock();
                if(this->command->first == "shoot" && this->command->second != "")
                {
                    std::cout << "A" << std::endl;
                    squareStatus_t status = this->playerB->shoot(this->command->second);
                    std::cout << "B" << std::endl;
                    if(status!=shootReturnStatus_t::ALREADYHIT)
                    {
                        std::cout << "C" << std::endl;
                        this->playerA->setOtherBoardSquareStatus(this->command->second,status);
                        std::cout << "D" << std::endl;
                    }
                    else
                        continue;
                }
                else if(this->command->first == "exit" || this->command->first == "quit")
                {
                    break;
                }
                else
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                    continue;
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                this->playerInTurn = 'B';
            }
            else if(this->playerInTurn == 'B')
            {
                lockB.unlock();
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                lockB.lock();
                
                if(this->command->first == "shoot" && this->command->second != "")
                {
                    squareStatus_t status = this->playerA->shoot(this->command->second);
                    if(status!=shootReturnStatus_t::ALREADYHIT)
                        this->playerB->setOtherBoardSquareStatus(this->command->second,status);
                    else
                        continue;
                }
                else if(this->command->first == "exit" || this->command->first == "quit")
                {
                    std::exit(0);
                }
                else
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                    continue;
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                this->playerInTurn = 'A';
            }
            else
            {
                this->playerInTurn = 'A';
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

        return true;
    }
}