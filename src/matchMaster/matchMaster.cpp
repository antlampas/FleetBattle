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
                                std::shared_ptr<command_t>               cA,
                                std::shared_ptr<asio::io_context>        ios,
                                playerInTurn_t                           p
                            ) : playerA        {pA},
                                playerB        {pB},
                                command        {cA},
                                ioContext      {ios},
                                socket         {std::make_shared<asio::ip::tcp::socket>(*this->ioContext)},
                                serviceChannel {std::make_shared<asio::ip::tcp::acceptor>(*this->ioContext,asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 2000))},
                                playerInTurn   {p}
    {

    }
}