/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "board.hpp"

class player
{
    private:
    std::shared_ptr<board>       adversairBoard {};
    std::shared_ptr<playerBoard> ownBoard       {};

    public:
    player();
    player(std::shared_ptr<playerBoard>);
    ~player();
};