/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>

#include "board.hpp"

#ifdef TESTPLAYER
#define private public
#endif

class player
{
    private:
    std::shared_ptr<opponentBoard> adversairBoard {};
    std::shared_ptr<playerBoard>   ownBoard       {};

    public:
    player();                              = delete;
    player(std::shared_ptr<playerBoard>);
    void shoot(coordinates_t coordinates);
};

#endif