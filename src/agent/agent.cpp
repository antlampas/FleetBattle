/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "agent.hpp"

#include <iostream>

namespace fleetBattle
{
    agent::agent(   playerInTurn_t                     p,
                    std::shared_ptr<matchMaster>       mm,
                    std::shared_ptr<std::mutex>        mtx,
                    std::shared_mutex&                 sMtx,
                    std::shared_ptr<command_t>         cmd,
                    std::shared_ptr<std::string>       serviceChannel,
                    int                                port
                )   :   standalone     {false},
                        mm             {mm},
                        mutex          {mtx},
                        serviceMutex   {sMtx},
                        command        {cmd},
                        serviceChannel {serviceChannel},
                        player         {p},
                        ioContext      {std::make_shared<asio::io_service>()},
                        socket         {std::make_shared<asio::ip::tcp::socket>(*this->ioContext)},
                        cli            {std::make_shared<asio::ip::tcp::acceptor>(*this->ioContext,asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))}
    {}
    agent::~agent()
    {}
}