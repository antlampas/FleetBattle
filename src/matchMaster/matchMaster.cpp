/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "matchMaster.hpp"

matchMaster::matchMaster(   std::shared_ptr<playerBoard> bA,
                            std::shared_ptr<playerBoard> bB,
                            std::shared_ptr<std::string> cA,
                            std::shared_ptr<std::string> cB
                        ) : playerBoardA(bA),
                            opponentBoardA(board()),
                            playerBoardB(bB),
                            opponentBoardB(board()),
                            command(std::string()),
                            playerInTurn('A'),
{

}