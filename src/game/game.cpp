/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "game.hpp"

namespace fleetBattle
{
  game::game( std::shared_ptr<command_t> commandPtr,
              deployedShips_t boardA,
              deployedShips_t boardB)                 :   playerA(new player( std::make_shared<fleetBattle::playerBoard>(new fleetBattle::playerBoard(boardA)),
                                                                              std::make_shared<fleetBattle::opponentBoard>(new fleetBattle::opponentBoard()),
                                                                              commandPtr,
                                                                              std::make_shared<std::mutex>(new std::mutex())
                                                                            )),
                                                          playerB(new player( std::make_shared<fleetBattle::playerBoard>(new fleetBattle::playerBoard(boardB)),
                                                                              std::make_shared<fleetBattle::opponentBoard>(new fleetBattle::opponentBoard()),
                                                                              commandPtr,
                                                                              std::make_shared<std::mutex>(new std::mutex())
                                                                            )),
                                                          mm( new matchMaster(std::shared_ptr<playerBoard>(playerA->ownBoard),
                                                                              std::shared_ptr<playerBoard>(playerB->ownBoard),
                                                                              std::shared_ptr<command_t>(std::make_pair<std::string,std::string>("","")),
                                                                              'A'
                                                                              )
                                                            )
  {}
}