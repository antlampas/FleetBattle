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
#include <chrono>
#include "boost/asio.hpp"

namespace fleetBattle
{
   class agent final
   {
       private:
       bool                                     standalone;
       playerInTurn_t                           player;
       std::shared_ptr<boost::asio::io_context>        ioContext;
       std::shared_ptr<boost::asio::ip::tcp::socket>   socket;
       std::shared_ptr<boost::asio::ip::tcp::acceptor> cli;
       std::shared_ptr<boost::asio::ip::tcp::socket>   serviceChannel;

       public:
       agent(  playerInTurn_t,
               std::shared_ptr<boost::asio::io_context>,
               int
           );
       ~agent();
       bool operator()();
   };
}

#endif