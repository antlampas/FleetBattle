/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "playerBoard.hpp"

bool playerBoard::hit(decodedCoordinatePair_t c)
{
    return false;
}
board_t playerBoard::getBoardStatus()
{
    return {};
}
squareStatus_t playerBoard::getSquareStatus(coordinates_t c)
{
    return {};
}
bool playerBoard::isSquareAlreadyHit(coordinates_t c)
{
    return false;
}
bool playerBoard::shoot(coordinates_t c)
{
    return false;
}
char playerBoard::squareStatus(coordinates_t c)
{
    return 'a';
}