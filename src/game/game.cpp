/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "game.hpp"
#include <iostream>

namespace fleetBattle
{
  game::game( std::shared_ptr<command_t> commandPtr,
              std::shared_ptr<std::mutex> mA,
              std::shared_ptr<std::mutex> mB,
              deployedShips_t deployedA,
              deployedShips_t deployedB)
  {
    this->playerA = std::make_shared<player>(
                                              player(
                                                      std::make_shared<playerBoard>(playerBoard(deployedA)),
                                                      std::make_shared<opponentBoard>(opponentBoard())
                                                    )
                                            );
    this->playerB = std::make_shared<player>(
                                              player(
                                                    std::make_shared<playerBoard>(playerBoard(deployedB) ),
                                                    std::make_shared<opponentBoard>(opponentBoard() )
                                                  )
                                            );
    this->mm      = std::make_shared<matchMaster> (
                                                    matchMaster(
                                                                  this->playerA,
                                                                  this->playerB,
                                                                  mA,
                                                                  mB,
                                                                  commandPtr,
                                                                  'A'
                                                                )
                                                  );
    this->agentA = std::make_shared<agent>(
                                            'A',
                                            this->mm->playerInTurn_public,
                                            mA,
                                            commandPtr,
                                            "/dev/ttyS0"
                                          );
    this->agentB = std::make_shared<agent>(
                                            'B',
                                            this->mm->playerInTurn_public,
                                            mB,
                                            commandPtr,
                                            "/dev/ttyS1"
                                          );
}
  game::~game(){}
}