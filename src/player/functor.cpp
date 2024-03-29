/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "player.hpp"

namespace fleetBattle
{
    namespace player
    {
        int player::operator()()
        {
            std::lock<std::mutex> 
            while(true)
            {
                std::lock_guard<std::mutex>(*(this->mutex));
                if(*(this->command).first.compare("shoot"))
                {
                    shootStatus_t status = this->ownBoard->shoot((*this->command).second);
                }
            }
            
            return 0;
        }
    }
}