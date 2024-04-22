/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "agent.hpp"

namespace fleetBattle
{
    agent::agent(   playerInTurn_t              p,
                    const playerInTurn_t&       pit,
                    std::shared_ptr<std::mutex> mtx,
                    std::shared_ptr<command_t>  cmd,
                    std::string                 filename
                )   :   standalone{false},
                        playerInTurn{pit},
                        mutex{mtx},
                        command{cmd},
                        player{p},
                        ioService{std::make_shared<boost::asio::io_service>()},
                        cli{std::make_shared<boost::asio::serial_port>(ioService)}
    {
        boost::system::error_code ec;

        m_port.open(filename, ec);

        if (!ec)
        {
            boost::asio::serial_port_base::baud_rate baud_rate1(9600);   
            m_port.set_option(baud_rate1);
        }
    }
    agent::~agent(){}
}