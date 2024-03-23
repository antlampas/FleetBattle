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

using command_t = std::pair<std::string,std::string>;

class player final
{
    private:
    std::shared_ptr<playerBoard>   ownBoard;
    std::shared_ptr<opponentBoard> otherBoard;
    std::shared_ptr<command_t>     command;

    public:
    player()                                                                                        = delete;
    player(std::shared_ptr<playerBoard>,std::shared_ptr<opponentBoard>,std::shared_ptr<command_t>);
    void          shoot(coordinates_t coordinates);
    board_t       checkOwnBoard();
    board_t       checkOpponentBoard();
    shootStatus_t shoot(std::string);
};

#endif