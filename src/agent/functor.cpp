/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

 namespace fleetBattle
 {
    void agent::operator()()
    {
        std::string command;

        while(true)
        {
            std::cin >> command;
            std::lock_guard(*this->mutex);
            auto pos = command.find(" ");
            if(pos != command.npos)
            {
                this->command->first  = command.substr(0,pos-1);
                this->command->second = command.substr(0,pos+1);
            }
            
            std::cout << command << std::endl << this->command->first << std::endl << this->command->second;

            if(this->command->first == "exit" || this->command->first == "quit")
            {
                break;
            }
        }
    }
 }