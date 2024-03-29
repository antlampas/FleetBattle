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
        matchMaster::matchMaster(   ::std::unique_ptr<board::playerBoard> bA,
                                    ::std::unique_ptr<board::playerBoard> bB,
                                    ::std::shared_ptr<board::command_t>   cA,
                                    board::playerInTurn_t               p
                                ) : playerBoardA(::std::move(bA)),
                                    playerBoardB(::std::move(bB)),
                                    command(::std::make_shared<command_t>(::std::make_pair("",""))),
                                    playerInTurn(p),
                                    mutex(new ::std::mutex())
        {}
    }
}