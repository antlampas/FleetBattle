#include <iostream>

#include "game.hpp"

int main(int argc,char** argv)
(
    std::shared_ptr<fleetBattle::command_t> cmd  = std::make_shared<fleetBattle::command_t>();
    std::shared_ptr<std::mutex>             mtxA = std::make_shared<std::mutex>();
    std::shared_ptr<std::mutex>             mtxB = std::make_shared<std::mutex>();

    fleetBattle::deployedShips_t deployedShipsA(std::make_pair("a1","a2"),std::make_pair("b1","b2"),std::make_pair("c1","c3"),std::make_pair("d1","d4"),std::make_pair("e1","e5"));
    fleetBattle::deployedShips_t deployedShipsB(std::make_pair("a1","a2"),std::make_pair("b1","b2"),std::make_pair("c1","c3"),std::make_pair("d1","d4"),std::make_pair("e1","e5"));

    std::unique_ptr<fleetBattle::game> fb(new fleetBattle::game(std::shared_ptr<fleetBattle::command_t>(cmd),std::shared_ptr<std::mutex> mtxA,std::shared_ptr<std::mutex> mtxB));

    return -1;
)