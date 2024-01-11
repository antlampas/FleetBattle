/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "board.hpp"
#include "matchMaster.hpp"
#include "player.hpp"

class game
{
    private:
    std::shared_ptr playerA     {};
    std::shared_ptr playerB     {};
    std::shared_ptr matchMaster {};

    public:
    game();
    ~game();
}