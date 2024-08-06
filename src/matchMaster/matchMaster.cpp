/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "matchMaster.hpp"

#include <functional>

namespace fleetBattle
{
    matchMaster::matchMaster(   std::shared_ptr<player>        pA,
                                std::shared_ptr<player>        pB,
                                std::shared_ptr<std::mutex>    mA,
                                std::shared_ptr<std::mutex>    mB,
                                std::shared_ptr<command_t>     cA,
                                playerInTurn_t                 p
                            ) : playerA(pA),
                                playerB(pB),
                                command(cA),
                                playerInTurn(p),
                                mutexA(mA),
                                mutexB(mB)
    {}
}