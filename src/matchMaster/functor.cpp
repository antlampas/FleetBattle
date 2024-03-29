/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "matchMaster.hpp"

namespace fleetBattle
{
    namespace matchMaster
    {
        int matchMaster::operator()()
        {
            std::unique_lock<std::mutex> lockA(*this->mutexA);
            std::unique_lock<std::mutex> lockB(*this->mutexB);


            while(true)
            {
                switch(this->playerInTurn)
                {
                    case 'A':
                        lockA.unlock();
                        std::this_thread::sleep_for(1ms);
                        lockA.try_lock();
                        this->playerInTurn = 'B';
                        break;
                    case 'B':
                        lockB.unlock();
                        std::this_thread::sleep_for(1ms);
                        lockB.try_lock();
                        this->playerInTurn = 'A';
                        break;
                    default:
                        this->playerInTurn = 'A';
                }
            }
            
            return 0;
        }
    }
}