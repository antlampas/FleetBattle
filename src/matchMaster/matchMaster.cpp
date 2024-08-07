/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "matchMaster.hpp"

#include <functional>

namespace fleetBattle
{
    matchMaster::matchMaster(   std::shared_ptr<player>            pA,
                                std::shared_ptr<player>            pB,
                                std::shared_ptr<command_t>         cA,
                                std::shared_ptr<std::string>       sc,
                                playerInTurn_t                     p
                            ) : playerA(pA),
                                playerB(pB),
                                command(cA),
                                serviceChannel(sc),
                                playerInTurn(p)
    {}
}