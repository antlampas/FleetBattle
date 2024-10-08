/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef MATCHMASTER_HPP
#define MATCHMASTER_HPP

#include "types.hpp"
#include "exceptions.hpp"
#include "player.hpp"
#include "playerBoard.hpp"
#include "opponentBoard.hpp"

#include <memory>
#include <future>
#include <thread>
#include <chrono>
#include "boost/asio.hpp"

#ifdef TESTMATCHMASTER
#define private public
#endif

namespace fleetBattle
{
    class matchMaster final
    {
        private:
        std::pair<playerInTurn_t,shipsSquaresList_t> ships;
        std::shared_ptr<player>                      playerA;
        std::shared_ptr<player>                      playerB;
        std::shared_ptr<command_t>                   command;
        playerInTurn_t                               playerInTurn;
        std::shared_ptr<boost::asio::io_context>            ioContext;
        std::shared_ptr<boost::asio::ip::tcp::socket>       socket;
        std::shared_ptr<boost::asio::ip::tcp::acceptor>     serviceChannel;

        private:
        bool isShipSunk();

        public:
        matchMaster() = delete;
        matchMaster(std::shared_ptr<player>,
                    std::shared_ptr<player>,
                    std::shared_ptr<boost::asio::io_context>,
                    playerInTurn_t
                    );
        bool operator()();
    };
}
#endif