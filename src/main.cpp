#include "opponentBoard.hpp"
#include "playerBoard.hpp"
#include "player.hpp"
#include "game.hpp"

#include <iostream>

int main(int argc,char** argv)
{
    deployedShips_t ds {};

    for(auto i: {0,1,2,3,4,5,6,7,8,9}) ds.push_back(std::vector<squareStatus_t>{10,'W'});
    
    ds.at(0).at(0) = 'S';
    ds.at(0).at(1) = 'S';

    ds.at(1).at(0) = 'S';
    ds.at(2).at(0) = 'S';
    ds.at(3).at(0) = 'S';

    ds.at(0).at(3) = 'S';
    ds.at(1).at(3) = 'S';
    ds.at(2).at(3) = 'S';
    ds.at(3).at(3) = 'S';

    playerBoard pb;

    return -1;
}