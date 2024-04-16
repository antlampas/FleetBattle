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
    this->playerA = std::move(std::make_shared<player>      {
                                                              new player  {       
                                                                            std::shared_ptr<playerBoard>   { new playerBoard(deployedA) },
                                                                            std::shared_ptr<opponentBoard> { new opponentBoard()        },
                                                                            commandPtr,
                                                                            mA
                                                                          }
                                                            });
    this->playerB = std::move(std::make_shared<player>      {
                                                              new player  {
                                                                            std::shared_ptr<playerBoard>   { new playerBoard(deployedB) },
                                                                            std::shared_ptr<opponentBoard> { new opponentBoard() },
                                                                            commandPtr,
                                                                            mB
                                                                          }
                                                            });
    this->mm      = std::move(std::make_shared<matchMaster> {
                                                              new matchMaster {
                                                                                this->playerA,
                                                                                this->playerB,
                                                                                this->playerA->ownBoard,
                                                                                this->playerB->ownBoard,
                                                                                mA,
                                                                                mB,
                                                                                commandPtr,
                                                                                'A'
                                                                              }
                                                            });
    this->agentA = std::shared_ptr<agent>{ new agent('A',this->mm->playerInTurn_public,mA,commandPtr) };
    this->agentB = std::shared_ptr<agent>{ new agent('B',this->mm->playerInTurn_public,mB,commandPtr) };
  }
  game::~game(){}
}