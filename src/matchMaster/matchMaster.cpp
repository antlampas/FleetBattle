/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "matchMaster.hpp"

namespace fleetBattle
{
    matchMaster::matchMaster(   std::unique_ptr<playerBoard> bA,
                                std::unique_ptr<playerBoard> bB,
                                std::shared_ptr<command_t>   cA,
                                playerInTurn_t                            p
                            ) : playerBoardA(std::move(bA)),
                                playerBoardB(std::move(bB)),
                                command(cA),
                                playerInTurn(p),
                                mutexA(new std::mutex()),
                                mutexB(new std::mutex()),
                                mutexCommand(new std::mutex())
    {}
}