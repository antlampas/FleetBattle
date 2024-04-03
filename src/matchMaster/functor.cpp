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
                std::cout << "Player A" << std::endl;
                lockA.unlock();
                std::packaged_task<void()> playerA(*(this->playerA));
                std::thread playerAThread(std::move(playerA));
                playerAThread.join();
                lockA.lock();
                if(this->command->first == "shoot")
                {
                    squareStatus_t status = this->playerBoardB->shoot(this->command->second);
                    this->playerA->otherBoard->setSquareStatus(this->command->second,status);
                }
                else if(this->command->first == "exit")
                {
                    break;
                }
                else
                {
                    continue;
                }
                this->playerInTurn = 'B';
            }
            else if(this->playerInTurn == 'B')
            {
                std::cout << "Player B" << std::endl;
                lockB.unlock();
                std::packaged_task<void()> playerB(*(this->playerB));
                std::thread playerBThread(std::move(playerB));
                playerBThread.join();
                lockB.lock();
                if(this->command->first == "shoot")
                {
                    squareStatus_t status = this->playerBoardA->shoot(this->command->second);
                    this->playerB->otherBoard->setSquareStatus(this->command->second,status);
                }
                else if(this->command->first == "exit")
                {
                    break;
                }
                else
                {
                    continue;
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