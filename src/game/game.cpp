/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "game.hpp"
#include <functional>

namespace fleetBattle
{
  game::game( std::shared_ptr<command_t>         commandPtr,
              std::shared_ptr<asio::io_context>  mmContext,
              std::shared_ptr<asio::io_context>  agentContext,
              deployedShips_t                    deployedA,
              deployedShips_t                    deployedB
            )
  {
    this->playerA = std::make_shared<player>( std::make_shared<playerBoard>(deployedA),
                                              std::make_shared<opponentBoard>()
                                            );
    this->playerB = std::make_shared<player>( std::make_shared<playerBoard>(deployedB),
                                              std::make_shared<opponentBoard>()
                                            );
    this->mm      = std::make_shared<matchMaster>(this->playerA,
                                                  this->playerB,
                                                  commandPtr,
                                                  mmContext,
                                                  'A'
                                                  );
    this->agentA  = std::make_shared<agent>('A',
                                            this->mm,
                                            commandPtr,
                                            agentContext,
                                            1024
                                            );
    this->agentB  = std::make_shared<agent>('B',
                                            this->mm,
                                            commandPtr,
                                            agentContext,
                                            1025
                                            );
  }
  game::~game(){}
}