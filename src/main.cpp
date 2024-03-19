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
    
    playerBoard pb {ds};

    board_t bs = pb.getBoardStatus();

    for(auto row: bs){
        for(auto column: row)
            std::cout << column << " ";
        std::cout << std::endl;
    }
    for(int i=0;i<std::string{"abcdefghij"}.size();i++)
    {
        std::string row = std::string{"abcdefghij"}.substr(i,1);
        for(auto column: {1,2,3,4,5,6,7,8,9,10})
        {
            std::string coord {row};
            std::cout << pb.getSquareStatus(coord.append(std::to_string(column))) << std::endl;
        }
    }
    return -1;
}