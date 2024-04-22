/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "game.hpp"

namespace fleetBattle
{
  game::game( std::shared_ptr<command_t> commandPtr,
              std::shared_ptr<std::mutex> mA,
              std::shared_ptr<std::mutex> mB,
              deployedShips_t deployedA,
              deployedShips_t deployedB)
  {
    this->playerA = std::shared_ptr<player>(
                                              new player(
                                                          std::shared_ptr<playerBoard>   { new playerBoard(deployedA) },
                                                          std::shared_ptr<opponentBoard> { new opponentBoard()        },
                                                          commandPtr,
                                                          mA
                                                        )
                                            );
    this->playerB = std::shared_ptr<player>(
                                              new player(
                                                          std::shared_ptr<playerBoard>   { new playerBoard(deployedB) },
                                                          std::shared_ptr<opponentBoard> { new opponentBoard() },
                                                          commandPtr,
                                                          mB
                                                        )
                                            );
    this->mm      = std::shared_ptr<matchMaster>(
                                                  new matchMaster(
                                                                  this->playerA,
                                                                  this->playerB,
                                                                  mA,
                                                                  mB,
                                                                  commandPtr,
                                                                  'A'
                                                                )
                                                );
    this->agentA = std::move(new agent(
                                        'A',
                                        this->mm->playerInTurn_public,
                                        mA,
                                        commandPtr,
                                        "/dev/tty0"
                                      ));
    this->agentB = std::move(new agent(
                                        'B',
                                        this->mm->playerInTurn_public,
                                        mB,
                                        commandPtr,
                                        "/dev/tty2"
                                      ));
}
  game::~game(){}
}