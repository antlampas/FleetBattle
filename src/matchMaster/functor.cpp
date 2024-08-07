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
        std::unique_lock lock(*this->serviceMutex);

        while(true)
        {
            if(this->playerInTurn == 'A')
            {
                *this->serviceChannel = 'A';

//                std::lock_guard<std::mutex> lockA(*this->mutexA);

                if(this->command->first == "shoot")
                {
                    squareStatus_t status = this->playerB->shoot(this->command->second);

                    if(status == shootReturnStatus_t::HIT)
                    {
                        this->playerA->setOtherBoardSquareStatus(this->command->second,status);
                    }
                    else if(status ==  shootReturnStatus_t::MISSED)
                    {
                        this->playerInTurn = 'B';
                    }
                    else if(status ==  shootReturnStatus_t::ALREADYHIT)
                    {}
                }
                else if(this->command->first == "exit" || this->command->first == "quit")
                {
                    std::exit(0);
                }
                this->command->first  = "";
                this->command->second = "";
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
            else if(this->playerInTurn == 'B')
            {
                *this->serviceChannel = 'B';

//                std::lock_guard<std::mutex> lockB(*this->mutexB);

                if(this->command->first == "shoot")
                {
                    squareStatus_t status = this->playerA->shoot(this->command->second);

                    if(status == shootReturnStatus_t::HIT)
                    {
                        this->playerB->setOtherBoardSquareStatus(this->command->second,status);
                    }
                    else if(status ==  shootReturnStatus_t::MISSED)
                    {
                        this->playerInTurn = 'A';
                    }
                    else if(status ==  shootReturnStatus_t::ALREADYHIT)
                    {}
                }
                else if(this->command->first == "exit" || this->command->first == "quit")
                {
                    std::exit(0);
                }
                this->command->first  = "";
                this->command->second = "";
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }

        return true;
    }
}