/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */
#ifndef MATCHMASTER_HPP
#define MATCHMASTER_HPP

#include <memory>

#include "playerBoard.hpp"

#ifdef TESTMATCHMASTER
#define private public
#endif

using playerInTurn_t = char;

class matchMaster
{
    private:
    std::pair<playerInTurn_t,std::vector<std::vector<squareStatus_T>>> ships;
    std::unique_ptr<board>       boardA;
    std::unique_ptr<board>       boardB;
    std::unique_ptr<std::string> command;
    playerInTurn_t playerInTurn;
    private:
    bool isShipSunk();

    public:
    matchMaster() = delete;
    matchMaster(board bA,board bB,std::string cA,std::string cB);
};

#endif