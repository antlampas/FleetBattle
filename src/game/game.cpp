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
              deployedShips_t deployedB)  :   playerA{new player( std::shared_ptr<fleetBattle::playerBoard>(new fleetBattle::playerBoard(deployedA)),
                                                                  std::shared_ptr<fleetBattle::opponentBoard>(new fleetBattle::opponentBoard()),
                                                                  std::shared_ptr<command_t>(commandPtr),
                                                                  std::shared_ptr<std::mutex>(mA))
                                              },
                                              playerB{new player( std::shared_ptr<fleetBattle::playerBoard>(new fleetBattle::playerBoard(deployedB)),
                                                                  std::shared_ptr<fleetBattle::opponentBoard>(new fleetBattle::opponentBoard()),
                                                                  std::shared_ptr<command_t>(commandPtr),
                                                                  std::shared_ptr<std::mutex>(mB))
                                              },
                                              mm{new matchMaster( this->playerA,
                                                                  this->playerB,
                                                                  std::shared_ptr<playerBoard>(playerA->ownBoard),
                                                                  std::shared_ptr<playerBoard>(playerB->ownBoard),
                                                                  std::shared_ptr<std::mutex>(mA),
                                                                  std::shared_ptr<std::mutex>(mB),
                                                                  std::shared_ptr<command_t>(commandPtr),
                                                                  'A')
                                              },
                                              agentA(new agent( 'A',
                                                                this->mm->playerInTurn_public,
                                                                std::shared_ptr<std::mutex>(mA),
                                                                std::shared_ptr<command_t>(commandPtr))
                                              ),
                                              agentB(new agent( 'B',
                                                                this->mm->playerInTurn_public,
                                                                std::shared_ptr<std::mutex>(mB),
                                                                std::shared_ptr<command_t>(commandPtr))
                                              )
  {}
  game::~game(){}
}