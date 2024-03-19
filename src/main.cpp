#include "opponentBoard.hpp"
#include "playerBoard.hpp"
#include "player.hpp"
#include "game.hpp"

#include <iostream>

int main(int argc,char** argv)
{
    deployedShips_t ds {};

    ds.push_back(std::pair<std::string,std::string>{"a1","a3"});
    ds.push_back(std::pair<std::string,std::string>{"b1","f1"});
    ds.push_back(std::pair<std::string,std::string>{"b3","b5"});

    std::size_t pos{};
    pos++;
    std::cout << pos << std::endl;

    playerBoard pb(ds);

    return -1;
}