/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef AGENT_HPP
#define AGENT_HPP

#include "types.hpp"
#include "matchMaster.hpp"

#include <memory>
#include <fstream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <chrono>
#include <asio.hpp>

namespace fleetBattle
{
   class agent final
   {
       private:
       bool                                            standalone;
       playerInTurn_t                                  player;
       std::shared_ptr<matchMaster>                    mm;
       std::shared_ptr<std::mutex>                     mutex;
       std::shared_mutex                               serviceMutex;
       std::shared_ptr<command_t>                      command;
       std::shared_ptr<asio::io_service>               ioContext;
       std::shared_ptr<asio::ip::tcp::socket>          socket;
       std::shared_ptr<asio::ip::tcp::acceptor>        cli;
       std::shared_ptr<std::string>                    serviceChannel;

       public:
       agent(  playerInTurn_t,
               std::shared_ptr<matchMaster>,
               std::shared_ptr<std::mutex>,
               std::shared_mutex&,
               std::shared_ptr<command_t>,
               std::shared_ptr<std::string>,
               int
           );
       ~agent();
       bool operator()();
   };
}

#endif