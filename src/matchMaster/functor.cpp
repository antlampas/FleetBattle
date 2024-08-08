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
        asio::error_code error;
        
        while(true)
        {
            if(this->playerInTurn == 'A')
            {
                asio::write(*this->socket,asio::buffer(std::string("A")),asio::transfer_at_least(1),error);

                if(this->command->first == "shoot")
                {
                    squareStatus_t status = this->playerB->shoot(this->command->second);

                    if(status == shootReturnStatus_t::HIT)
                    {
                        this->playerA->setOtherBoardSquareStatus(this->command->second,status);
                    }
                    else if(status ==  shootReturnStatus_t::MISSED)
                    {
                        this->playerInTurn    = 'B';
                        asio::write(*this->socket,asio::buffer(std::string("B")),asio::transfer_at_least(1),error);
                    }
                    else if(status ==  shootReturnStatus_t::ALREADYHIT)
                    {}
                }
                else if(this->command->first == "exit" || this->command->first == "quit")
                {
                    std::exit(0);
                }
            }
            else if(this->playerInTurn == 'B')
            {
                asio::write(*this->socket,asio::buffer(std::string("B")),asio::transfer_at_least(1),error);

                if(this->command->first == "shoot")
                {
                    squareStatus_t status = this->playerA->shoot(this->command->second);

                    if(status == shootReturnStatus_t::HIT)
                    {
                        this->playerB->setOtherBoardSquareStatus(this->command->second,status);
                    }
                    else if(status ==  shootReturnStatus_t::MISSED)
                    {
                        this->playerInTurn    = 'A';
                        asio::write(*this->socket,asio::buffer(std::string("B")),asio::transfer_at_least(1),error);
                    }
                    else if(status ==  shootReturnStatus_t::ALREADYHIT)
                    {}
                }
                else if(this->command->first == "exit" || this->command->first == "quit")
                {
                    std::exit(0);
                }
            }
            this->command->first  = "";
            this->command->second = "";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        return true;
    }
}