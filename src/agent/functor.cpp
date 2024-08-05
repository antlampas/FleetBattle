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
        asio::streambuf input {};
        asio::error_code error;
        
        this->cli->accept(*this->socket);
        
        this->standalone = true;
        
        while(true)
        {
            output = std::string(1,this->player) + std::string(": waiting for your turn...\n");
            asio::write(*this->socket,asio::buffer(output.c_str(),output.size()),asio::transfer_at_least(output.size()),error);

            while(*this->playerInTurn != this->player)
            {
                std::lock_guard<std::mutex> lock(*this->mutex);
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            
            if(*this->playerInTurn == this->player)
            {   
                this->command->first = this->command->second = "";
                
                output = std::string("\nPlayer ") + std::string(1,this->player) + std::string("\nCommand: ");
                asio::write(*this->socket,asio::buffer(output.c_str(),output.size()),asio::transfer_at_least(output.size()),error);
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                asio::read(*this->socket,input,asio::transfer_at_least(1), error);
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
                    asio::write(*this->socket,asio::buffer(this->command->first.c_str(),this->command->first.size()),asio::transfer_at_least(output.size()),error);
                }
                if((this->command->first == "exit") || (this->command->first == "quit"))
                {
                    break;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        return true;
    }
}