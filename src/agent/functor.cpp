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
        std::string output          {};
        asio::streambuf input       {};
        asio::streambuf inputPlayer {};
        asio::error_code            error;

        unsigned char playerInTurn = 'A';

        this->standalone = true;

        while(true)
        {
            asio::read_until(*this->serviceChannel,inputPlayer,"\n");
            std::string playerInTurn = std::string(std::istreambuf_iterator<char>(&inputPlayer), std::istreambuf_iterator<char>());

            std::this_thread::sleep_for(std::chrono::milliseconds(10));

            output = std::string(1,this->player) + std::string(": waiting for your turn...\nPlayer in turn: " + playerInTurn + "\n");
            asio::write(*this->socket,asio::buffer(output.c_str(),output.size()),asio::transfer_at_least(output.size()),error);
            
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

            if(playerInTurn.at(0) == this->player)
            {
                std::string ready(std::string(1,this->player) + " ready\n");
                asio::write(*this->serviceChannel,asio::buffer(ready.c_str(),ready.size()),asio::transfer_at_least(ready.size()),error);
                
                output = std::string("\nPlayer ") + std::string(1,this->player) + std::string("\nCommand: ");
                asio::write(*this->socket,asio::buffer(output.c_str(),output.size()),asio::transfer_at_least(output.size()),error);
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                asio::read_until(*this->socket,input,"\n");
                std::string cmd = std::string(std::istreambuf_iterator<char>(&input), std::istreambuf_iterator<char>());
                
                asio::write(*this->serviceChannel,asio::buffer(cmd.c_str(),cmd.size()),asio::transfer_at_least(cmd.size()),error);
                asio::write(*this->socket,asio::buffer(cmd.c_str(),cmd.size()),asio::transfer_at_least(cmd.size()),error);

                cmd.erase(cmd.size()-1);
                auto pos = cmd.find(' ');

                std::vector<std::string> cmdVec {};
                if(pos != cmd.npos)
                {
                    cmdVec.push_back(cmd.substr(0,pos));
                    cmdVec.push_back(cmd.substr(++pos,cmd.npos));
                }
                else
                {
                    cmdVec.push_back(cmd);
                }
                if((cmdVec.at(0) == "exit") || (cmdVec.at(0) == "quit"))
                {
                    break;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(70));
        }
        return true;
    }
}