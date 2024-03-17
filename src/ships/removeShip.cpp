/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "ships.hpp"

void ships::removeShip(std::string ship)
{
    this->shipsList.erase(ship);
}