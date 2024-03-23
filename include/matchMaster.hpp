/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */
#ifndef MATCHMASTER_HPP
#define MATCHMASTER_HPP

#include <memory>

#include "playerBoard.hpp"
#include "opponentBoard.hpp"

#ifdef TESTMATCHMASTER
#define private public
#endif

using playerInTurn_t     = char;
using shipsSquaresList_t = std::vector<std::vector<squareStatus_t>>;

class matchMaster final
{
    private:
    std::pair<playerInTurn_t,shipsSquaresList_t> ships;
    std::unique_ptr<playerBoard> playerBoardA;
    std::unique_ptr<playerBoard> playerBoardB;
    std::shared_ptr<std::string> command;
    playerInTurn_t               playerInTurn;
    std::mutex                   mtx;
    private:
    bool isShipSunk();

    public:
    matchMaster() = delete;
    matchMaster(std::shared_ptr<playerBoard>,std::shared_ptr<playerBoard>,std::shared_ptr<std::string>,std::shared_ptr<std::string>,playerInTurn_t);
    void match();
};

#endif