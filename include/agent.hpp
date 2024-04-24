/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef AGENT_HPP
#define AGENT_HPP

#include "types.hpp"

#include <memory>
#include <fstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <boost/asio.hpp>
#include <spdlog/spdlog.h>

namespace fleetBattle
{
   class agent final
   {
       private:
       bool                                      standalone;
       playerInTurn_t                            player;
       const playerInTurn_t&                     playerInTurn;
       std::shared_ptr<std::mutex>               mutex;
       std::shared_ptr<command_t>                command;
       std::shared_ptr<boost::asio::io_service>  ioService;
       std::shared_ptr<boost::asio::serial_port> cli;

       public:
       agent(  playerInTurn_t,
               const playerInTurn_t&,
               std::shared_ptr<std::mutex>,
               std::shared_ptr<command_t>,
               std::string
           );
       ~agent();
       bool operator()();
   };
}

#endif