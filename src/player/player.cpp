/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "player.hpp"

namespace fleetBattle
{
    namespace player
    {
        player::player( std::shared_ptr<playerBoard> pb,
                        std::shared_ptr<opponentBoard> ob,
                        std::shared_ptr<command_t> c,
                        std::shared_ptr<std::mutex> m
                    ) : ownBoard(pb),
                        otherBoard(ob),
                        command(c),
                        mutex(m)
        {}
    }
}