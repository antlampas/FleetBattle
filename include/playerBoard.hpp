/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef PLAYERBOARD_HPP
#define PLAYERBOARD_HPP

#include "board.hpp"
#include "ships.hpp"

class playerBoard : public board
{
    private:
    deployedShips_t        deployedShips  {};
    private:
    virtual bool           hit(decodedCoordinatePair_t)      override final;
    public:
    playerBoard(deployedShips_t);
    playerBoard()                                            = delete;
    virtual board_t        getBoardStatus()                  override final;
    virtual squareStatus_t getSquareStatus(coordinates_t)    override final;
    virtual bool           isSquareAlreadyHit(coordinates_t) override final;
    virtual bool           shoot(coordinates_t)              override final;
    virtual char           squareStatus(coordinates_t)       override final;
};

#endif