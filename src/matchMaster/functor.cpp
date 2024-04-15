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
                std::this_thread::sleep_for(1ms);
                lockA.lock();
                if(this->command->first == "shoot" && this->command->second != "")
                {
                    squareStatus_t status = this->playerB->shoot(this->command->second);
                    this->playerA->otherBoard->setSquareStatus(this->command->second,status);
                }
                else if(this->command->first == "exit" || this->command->first == "quit")
                {
                    break;
                }
                else
                {
                    continue;
                }
                
                board_t opponentBoard = this->playerA->checkOpponentBoard();
                for(auto row: opponentBoard)
                {
                    for(auto column: row)
                    {
                        std::cout << column << " ";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                board_t ownBoard = this->playerA->checkOwnBoard();
                for(auto row: ownBoard)
                {
                    for(auto column: row)
                    {
                        std::cout << column << " ";
                    }
                    std::cout << std::endl;
                }

                this->playerInTurn = 'B';
            }
            else if(this->playerInTurn == 'B')
            {
                std::cout << "Player B" << std::endl;
                lockB.unlock();
                std::this_thread::sleep_for(1ms);
                lockB.lock();
                
                if(this->command->first == "shoot" && this->command->second != "")
                {
                    squareStatus_t status = this->playerA->shoot(this->command->second);
                    this->playerB->otherBoard->setSquareStatus(this->command->second,status);
                }
                else if(this->command->first == "exit" || this->command->first == "quit")
                {
                    break;
                }
                else
                {
                    continue;
                }
                
                board_t opponentBoard = this->playerB->checkOpponentBoard();
                for(auto row: opponentBoard)
                {
                    for(auto column: row)
                    {
                        std::cout << column << " ";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
                board_t ownBoard = this->playerB->checkOwnBoard();
                for(auto row: ownBoard)
                {
                    for(auto column: row)
                    {
                        std::cout << column << " ";
                    }
                    std::cout << std::endl;
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