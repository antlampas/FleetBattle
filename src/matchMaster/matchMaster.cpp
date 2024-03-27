/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "matchMaster.hpp"

matchMaster::matchMaster(   playerBoard*   bA,
                            playerBoard*   bB,
                            command_t*     cA,
                            playerInTurn_t p
                        ) : playerBoardA(bA),
                            playerBoardB(bB),
                            command(new command_t),
                            playerInTurn(p)
{}