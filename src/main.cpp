#include <iostream>
#include <memory>

#include "types.hpp"
#include "exceptions.hpp"
#include "game.hpp"

int main(int argc,char** argv)
{
    std::shared_ptr<fleetBattle::command_t> cmd      { new fleetBattle::command_t() };
    std::shared_ptr<std::mutex>             mutexA   { new std::mutex()             };
    std::shared_ptr<std::mutex>             mutexB   { new std::mutex()             };
    std::shared_ptr<std::mutex>             mutexCmd { new std::mutex()             };

    fleetBattle::deployedShips_t deployedShipsA {std::make_pair("a1","a2"),std::make_pair("b1","b2"),std::make_pair("c1","c3"),std::make_pair("d1","d4"),std::make_pair("e1","e5")};
    fleetBattle::deployedShips_t deployedShipsB {std::make_pair("a1","a2"),std::make_pair("b1","b2"),std::make_pair("c1","c3"),std::make_pair("d1","d4"),std::make_pair("e1","e5")};

    std::unique_ptr<fleetBattle::game> fb(new fleetBattle::game(cmd,mutexA,mutexB,mutexCmd,deployedShipsA,deployedShipsB));

    return -1;
}