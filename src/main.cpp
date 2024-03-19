#include "opponentBoard.hpp"
#include "playerBoard.hpp"
#include "player.hpp"
#include "game.hpp"

#include <iostream>

int main(int argc,char** argv)
{
    deployedShips_t ds {};

    ds.push_back(std::pair<std::string,std::string>{"a1","a3"});
    ds.push_back(std::pair<std::string,std::string>{"c1","g1"});
    ds.push_back(std::pair<std::string,std::string>{"b3","b5"});
    ds.push_back(std::pair<std::string,std::string>{"c3","c5"});
    ds.push_back(std::pair<std::string,std::string>{"g6","i6"});
    ds.push_back(std::pair<std::string,std::string>{"g10","j10"});

    try
    {
        playerBoard pb {ds};
    }
    catch(shipNotValid e)
    {
        std::cout << e.what() << std::endl;
    }

    return -1;
}