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

class matchMaster
{
    private:
    std::vector<shipSize_t> ships {};
    std::unique_ptr<board>  boardA;
    std::unique_ptr<board>  boardB;

    bool isShipSunk();

    public:
    matchMaster();
};

#endif