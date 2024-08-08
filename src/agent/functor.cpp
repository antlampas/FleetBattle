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
        std::string output          {};
        asio::streambuf input       {};
        asio::streambuf inputPlayer {};
        asio::error_code            error;

        unsigned char playerInTurn = 'A';

        this->cli->accept(*this->socket);

        this->standalone = true;

        while(true)
        {
            asio::read_until(*this->serviceChannel,inputPlayer,"\n");

            std::this_thread::sleep_for(std::chrono::milliseconds(10));

            std::string playerInTurn = std::string(std::istreambuf_iterator<char>(&inputPlayer), std::istreambuf_iterator<char>());
            
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

            output = std::string(1,this->player) + std::string(": waiting for your turn...\nPlayer in turn: " + playerInTurn + "\n");
            asio::write(*this->socket,asio::buffer(output.c_str(),output.size()),asio::transfer_at_least(output.size()),error);
            
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            
            std::cerr << "Agent: " << playerInTurn << std::endl;

            if(playerInTurn.at(0) == this->player)
            {
                this->command->first = this->command->second = "";
                
                output = std::string("\nPlayer ") + std::string(1,this->player) + std::string("\nCommand: ");
                asio::write(*this->socket,asio::buffer(output.c_str(),output.size()),asio::transfer_at_least(output.size()),error);
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                asio::read_until(*this->socket,input,"\n");
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
            std::this_thread::sleep_for(std::chrono::milliseconds(70));
        }
        return true;
    }
}