/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "agent.hpp"
#include <chrono>

namespace fleetBattle
{
    bool agent::operator()()
    {
        std::string output {};
        boost::asio::streambuf input {};
        boost::system::error_code error;
        
        this->cli->accept(*this->socket);
        
        while(true)
        {
            this->standalone = true;

            output = std::string(this->player,1) + std::string(": ") + std::string("waiting for your turn...\n");
            boost::asio::write(*this->socket,boost::asio::buffer(output.c_str(),output.size()),boost::asio::transfer_at_least(output.size()),error);
            std::unique_lock<std::mutex> lock(*(this->mutex));

            if(*this->playerInTurn == this->player)
            {   
                this->command->first = this->command->second = "";
                
                output = std::string("\n") + std::string("Player ") + std::string(this->player,1) + std::string("\n") + std::string("Command: ");
                boost::asio::write(*this->socket,boost::asio::buffer(output.c_str(),output.size()),boost::asio::transfer_at_least(output.size()),error);
                boost::asio::read(*this->socket,input,boost::asio::transfer_at_least(1), error);
                std::string cmd = std::string(std::istreambuf_iterator<char>(&input), std::istreambuf_iterator<char>());
                
                cmd.erase(cmd.size()-1);

                auto pos = cmd.find(' ');

                if(pos != cmd.npos)
                {
                    this->command->first  = cmd.substr(0,pos);
                    this->command->second = cmd.substr(++pos,cmd.npos);
                }
                else
                {
                    this->command->first  = cmd;
                    boost::asio::write(*this->socket,boost::asio::buffer(this->command->first.c_str(),this->command->first.size()),boost::asio::transfer_at_least(output.size()),error);
                }
                if((this->command->first == "exit") || (this->command->first == "quit"))
                {
                    break;
                }
            }
        }
        return true;
    }
}