/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "agent.hpp"

namespace fleetBattle
{
    agent::agent(   playerInTurn_t                    p,
                    std::shared_ptr<boost::asio::io_context> ioContext,
                    int                               port
                )   :   standalone     {false},
                        player         {p},
                        ioContext      {ioContext},
                        socket         {std::make_shared<boost::asio::ip::tcp::socket>(*this->ioContext)},
                        cli            {std::make_shared<boost::asio::ip::tcp::acceptor>(*this->ioContext,boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))},
                        serviceChannel {std::make_shared<boost::asio::ip::tcp::socket>(*this->ioContext)}
    {
        this->cli->accept(*this->socket);
        this->serviceChannel->connect(boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),2000));
    }
    agent::~agent()
    {}
}