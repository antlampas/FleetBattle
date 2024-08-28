/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <memory>
#include <thread>

#include "agent.hpp"
#include "board.hpp"
#include "exceptions.hpp"
#include "game.hpp"
#include "matchMaster.hpp"
#include "opponentBoard.hpp"
#include "player.hpp"
#include "playerBoard.hpp"
#include "ships.hpp"
#include "types.hpp"
#include "utilities.hpp"

int main(int argc,char** argv)
{
    std::shared_ptr<fleetBattle::command_t> cmd { std::make_shared<fleetBattle::command_t>() };

    fleetBattle::deployedShips_t deployedShipsA {std::make_pair("a1","a2"),std::make_pair("b1","b2"),std::make_pair("c1","c3"),std::make_pair("d1","d4"),std::make_pair("e1","e5")};
    fleetBattle::deployedShips_t deployedShipsB {std::make_pair("a1","a2"),std::make_pair("b1","b2"),std::make_pair("c1","c3"),std::make_pair("d1","d4"),std::make_pair("e1","e5")};

    std::shared_ptr<fleetBattle::game> game = std::make_shared<fleetBattle::game>(std::make_shared<asio::io_context>(),std::make_shared<asio::io_context>(),deployedShipsA,deployedShipsB);
    std::thread gameThread {*game};

    gameThread.join();
    
    return 0;
}