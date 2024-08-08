/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "matchMaster.hpp"

#include <cstdlib>

namespace fleetBattle
{
    void h(const asio::error_code& ec,std::size_t bytes_transferred){};

    bool matchMaster::operator()()
    {
        asio::error_code error;
        asio::streambuf agentInput {};

        while(true)
        {
            asio::async_write(*this->socket,asio::buffer(std::string(1,this->playerInTurn)+std::string(1,'\n')),&h);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            
            asio::read_until(*this->socket,agentInput,"\n");
            std::string agentInputString {std::string(std::istreambuf_iterator<char>(&agentInput), std::istreambuf_iterator<char>())};
            
            if(agentInputString.find("ready") >= 0)
            {}

            asio::read_until(*this->socket,agentInput,"\n");
            agentInputString.erase(agentInputString.size()-1);
            auto pos = agentInputString.find(' ');
            if(pos != agentInputString.npos)
            {
                this->command->first  = agentInputString.substr(0,pos);
                this->command->second = agentInputString.substr(++pos,agentInputString.npos);
            }
            else
            {
                this->command->first = agentInputString;
            }

            if(this->playerInTurn == 'A')
            {
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
            }
            else if(this->playerInTurn == 'B')
            {
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