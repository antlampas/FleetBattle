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
        this->cli << "Player " << this->player << " running on thread " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(1ms);
        while(true)
        {
            std::this_thread::sleep_for(1ms);

            this->standalone = true;

            std::string cmd;

            {
                std::unique_lock<std::mutex> lock(*(this->mutex));
                this->cli << this->player << ": " << "waiting for your turn...";
            }
            std::this_thread::sleep_for(1ms);
            std::unique_lock<std::mutex> lock(*(this->mutex));

            if(this->playerInTurn == this->player)
            {   
                this->command->first = this->command->second = "";
                
                this->cli << std::endl << "Player " << this->player << std::endl << "Command: ";
                std::getline(this->cli,cmd);
                
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
            std::this_thread::sleep_for(1ms);
        }
        std::this_thread::sleep_for(1ms);
        return true;
    }
}