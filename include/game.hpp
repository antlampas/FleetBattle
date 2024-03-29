/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "board.hpp"
#include "matchMaster.hpp"
#include "player.hpp"

#ifdef TESTGAME
#define private public
#endif

class game final
{
    private:
    std::shared_ptr<player>     playerA {};
    std::shared_ptr<player>     playerB {};
    std::shared_ptr<matchMaster> mm     {};

    public:
    game();
};