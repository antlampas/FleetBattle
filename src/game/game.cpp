/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "game.hpp"

namespace fleetBattle
{
    game::game()    :   playerA(new player()),
                        playerB(new player()),
                        mm(new matchMaster(
                                            std::unique_ptr<playerBoard>(playerA->board),
                                            std::unique_ptr<playerBoard>(playerB->board),
                                            std::shared_ptr<command_t>(std::make_pair<std::string,std::string>("","")),
                                            'A'
                                            )
                            )
    {}
}