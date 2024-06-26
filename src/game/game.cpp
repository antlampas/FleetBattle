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
              deployedShips_t deployedB
            )
  {
    this->playerA = std::make_shared<player>(std::make_shared<playerBoard>(deployedA),std::make_shared<opponentBoard>());
    this->playerB = std::make_shared<player>(std::make_shared<playerBoard>(deployedB),std::make_shared<opponentBoard>());
    this->mm      = std::make_shared<matchMaster>(this->playerA,this->playerB,mA,mB,commandPtr,'A');
    this->agentA  = std::make_shared<agent>('A',std::make_shared<const playerInTurn_t>(this->mm->playerInTurn_public),mA,commandPtr,1024);
    this->agentB  = std::make_shared<agent>('B',std::make_shared<const playerInTurn_t>(this->mm->playerInTurn_public),mB,commandPtr,1025);
  }
  game::~game(){}
}