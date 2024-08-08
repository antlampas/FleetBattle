/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "game.hpp"
#include <functional>

namespace fleetBattle
{
  game::game(
              std::shared_ptr<asio::io_context>  mmContext,
              std::shared_ptr<asio::io_context>  agentContext,
              deployedShips_t                    deployedA,
              deployedShips_t                    deployedB
            )
  {
    this->playerA = std::make_shared<player>( std::make_shared<playerBoard>(deployedA),
                                              std::make_shared<opponentBoard>()
                                            );
    this->playerB = std::make_shared<player>( std::make_shared<playerBoard>(deployedB),
                                              std::make_shared<opponentBoard>()
                                            );

    std::packaged_task<std::shared_ptr<matchMaster>()> makeMM([&](){
      return std::make_shared<matchMaster>(this->playerA,this->playerB,mmContext,'A');
    });
    std::packaged_task<std::shared_ptr<agent>()> makeAgentA([&](){
      return std::make_shared<agent>('A',agentContext,1024);
    });
    std::packaged_task<std::shared_ptr<agent>()> makeAgentB([&](){
      return std::make_shared<agent>('B',agentContext,1025);
    });

    std::future<std::shared_ptr<matchMaster>> futureMM = makeMM.get_future();
    std::future<std::shared_ptr<agent>> futureAgentA   = makeAgentA.get_future();
    std::future<std::shared_ptr<agent>> futureAgentB   = makeAgentB.get_future();
    std::thread makeMMThread(std::move(makeMM));
    std::thread makeAgentAThread(std::move(makeAgentA));
    std::thread makeAgentBThread(std::move(makeAgentB));
    
    makeMMThread.join();
    makeAgentAThread.join();
    makeAgentBThread.join();

    this->mm = futureMM.get();
    this->agentA = futureAgentA.get();
    this->agentB = futureAgentB.get();
  }
  game::~game(){}
}