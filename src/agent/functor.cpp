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
        while(true)
        {
            std::this_thread::sleep_for(1ms);

            this->standalone = true;

            std::string command;

            std::cout << "Waiting for your turn...";
            if(this->playerInTurn == this->player)
            {
                std::lock_guard<std::mutex> lock(*this->mutex);
                
                this->command->first = this->command->second = "";
                
                std::cout << std::endl << "Command: ";
                std::getline(std::cin,command);
                
                auto pos = command.find(' ');
                
                if(pos != command.npos)
                {
                    this->command->first  = command.substr(0,pos);
                    this->command->second = command.substr(++pos,command.npos);
                }
                else
                {
                    this->command->first  = command;
                }
                if((this->command->first == "exit") || (this->command->first == "quit"))
                    break;
            }
            else
            {
                std::this_thread::sleep_for(1ms);
            }
        }
        
        return true;
    }
 }