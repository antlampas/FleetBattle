/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "agent.hpp"
#include <chrono>
#include <iostream>

namespace fleetBattle
{
    bool agent::operator()()
    {
        std::string output {std::string("Player ") + std::string(this->player,1) + std::string(" running on thread ") + std::string(std::this_thread::get_id()) + std::string(std::endl,1)};
        boost::asio::streambuf input {};
        boost::system::error_code error;

        boost::asio::write(*this->cli,boost::asio::buffer(output.c_str(),output.size()),boost::asio::transfer_at_least(output.size()));

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        while(true)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));

            this->standalone = true;

            std::string cmd;

            {
                std::unique_lock<std::mutex> lock(*(this->mutex));
                output = std::string(this->player) + std::string(": ") + std::string("waiting for your turn...");
                boost::asio::write(*this->cli,boost::asio::buffer(output.c_str(),output.size()),boost::asio::transfer_at_least(output.size()),error);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::unique_lock<std::mutex> lock(*(this->mutex));

            if(this->playerInTurn == this->player)
            {   
                this->command->first = this->command->second = "";
                
                output = std::string(std::endl) + std::string("Player ") + std::string(this->player) + std::string(std::endl) + std::string("Command: ");
                boost::asio::write(*this->cli,boost::asio::buffer(output.c_str(),output.size()),boost::asio::transfer_at_least(output.size()),error);
                boost::asio::read(*this->cli,input,boost::asio::transfer_at_least(0), error);
                cmd = std::string(std::istreambuf_iterator<char>(&input), std::istreambuf_iterator<char>());
                
                auto pos = cmd.find(' ');

                if(pos != cmd.npos)
                {
                    this->command->first  = cmd.substr(0,pos);
                    this->command->second = cmd.substr(++pos,cmd.npos);
                }
                else
                {
                    this->command->first  = cmd;
                }
                if((this->command->first == "exit") || (this->command->first == "quit"))
                {
                    break;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        return true;
    }
}