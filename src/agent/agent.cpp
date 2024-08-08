/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "agent.hpp"

#include <iostream>

namespace fleetBattle
{
    agent::agent(   playerInTurn_t                    p,
                    std::shared_ptr<matchMaster>      mm,
                    std::shared_ptr<command_t>        cmd,
                    std::shared_ptr<asio::io_context> ioContext,
                    int                               port
                )   :   standalone     {false},
                        mm             {mm},
                        command        {cmd},
                        player         {p},
                        ioContext      {ioContext},
                        socket         {std::make_shared<asio::ip::tcp::socket>(*this->ioContext)},
                        cli            {std::make_shared<asio::ip::tcp::acceptor>(*this->ioContext,asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))},
                        serviceChannel {std::make_shared<asio::ip::tcp::socket>(*this->ioContext)}
    {
        std::cerr << "Agent " << std::string(1,this->player) << " server starting..." << std::endl;
        this->cli->async_accept(*this->socket);
        std::cerr << "Agent " << std::string(1,this->player) << " server started!" << std::endl;
    }
    agent::~agent()
    {}
}