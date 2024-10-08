/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "matchMaster.hpp"

#include <functional>

namespace fleetBattle
{
    matchMaster::matchMaster(   std::shared_ptr<player>                  pA,
                                std::shared_ptr<player>                  pB,
                                std::shared_ptr<boost::asio::io_context>        ios,
                                playerInTurn_t                           p
                            ) : playerA        {pA},
                                playerB        {pB},
                                command        {std::make_shared<command_t>()},
                                ioContext      {ios},
                                socket         {std::make_shared<boost::asio::ip::tcp::socket>(*this->ioContext)},
                                serviceChannel {std::make_shared<boost::asio::ip::tcp::acceptor>(*this->ioContext,boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 2000))},
                                playerInTurn   {p}
    {
        this->serviceChannel->accept(*this->socket);
    }
}