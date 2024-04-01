/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "agent.hpp"

 namespace fleetBattle
 {
    void agent::operator()()
    {
        std::string command;

        while(true)
        {
            
            std::cout << "Command: ";
            std::getline(std::cin,command);

            std::lock_guard<std::mutex>(*this->mutex);
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
            {
                break;
            }
            this->command->first = this->command->second = "";
        }
    }
 }