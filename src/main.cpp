#include <iostream>
#include <memory>
#include <thread>

#include "types.hpp"
#include "exceptions.hpp"
#include "game.hpp"
#include "agent.hpp"

int main(int argc,char** argv)
{
    std::shared_ptr<fleetBattle::command_t> cmd      { new fleetBattle::command_t() };
    std::shared_ptr<std::mutex>             mutexA   { new std::mutex()             };
    std::shared_ptr<std::mutex>             mutexB   { new std::mutex()             };
    std::shared_ptr<std::mutex>             mutexCmd { new std::mutex()             };

    fleetBattle::deployedShips_t deployedShipsA {std::make_pair("a1","a2"),std::make_pair("b1","b2"),std::make_pair("c1","c3"),std::make_pair("d1","d4"),std::make_pair("e1","e5")};
    fleetBattle::deployedShips_t deployedShipsB {std::make_pair("a1","a2"),std::make_pair("b1","b2"),std::make_pair("c1","c3"),std::make_pair("d1","d4"),std::make_pair("e1","e5")};

    std::shared_ptr<fleetBattle::game> game(new fleetBattle::game(cmd,mutexA,mutexB,deployedShipsA,deployedShipsB));
    std::thread gameThread(*(game)); 
    gameThread.join();

    return -1;
}