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
        while(true)
        {
            if(this->playerInTurn == 'A')
            {
                std::lock_guard<std::mutex> lockA(*this->mutexA);

                if(this->command->first != "") std::cerr << this->command->first << " " << this->command->second << std::endl;
                if(this->command->first == "shoot" && this->command->second != "")
                {
                    squareStatus_t status = this->playerB->shoot(this->command->second);
                    if(status!=shootReturnStatus_t::ALREADYHIT)
                    {
                        this->playerA->setOtherBoardSquareStatus(this->command->second,status);
                        this->command->first  = "";
                        this->command->second = "";
                    }
                    else
                    {
                        this->command->first  = "";
                        this->command->second = "";
                        std::this_thread::sleep_for(std::chrono::milliseconds(100));
                        continue;
                    }
                }
                else if(this->command->first == "exit" || this->command->first == "quit")
                {
                    std::exit(0);
                }
                else
                {
                    this->command->first  = "";
                    this->command->second = "";
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                    continue;
                }
                this->command->first  = "";
                this->command->second = "";
                this->playerInTurn = 'B';
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
            else if(this->playerInTurn == 'B')
            {
                std::lock_guard<std::mutex> lockB(*this->mutexB);

                if(this->command->first != "") std::cerr << this->command->first << " " << this->command->second << std::endl;
                if(this->command->first == "shoot" && this->command->second != "")
                {
                    squareStatus_t status = this->playerA->shoot(this->command->second);
                    if(status!=shootReturnStatus_t::ALREADYHIT)
                    {
                        this->playerB->setOtherBoardSquareStatus(this->command->second,status);
                        this->command->first  = "";
                        this->command->second = "";
                    }
                    else
                    {
                        this->command->first  = "";
                        this->command->second = "";
                        std::this_thread::sleep_for(std::chrono::milliseconds(100));
                        continue;
                    }
                }
                else if(this->command->first == "exit" || this->command->first == "quit")
                {
                    std::exit(0);
                }
                else
                {
                    this->command->first  = "";
                    this->command->second = "";
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                    continue;
                }
                this->command->first  = "";
                this->command->second = "";
                this->playerInTurn = 'A';
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
            else
            {
                this->command->first  = "";
                this->command->second = "";
                this->playerInTurn = 'A';
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        return true;
    }
}