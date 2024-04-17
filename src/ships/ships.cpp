/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "ships.hpp"

namespace fleetBattle
{
    ships::ships(shipsList_t ships)  : publicShipsList(this->shipsList),shipsList(std::move(ships))
    {}

    ships::ships(shipsList_t ships) : publicShipsList(this->shipsList)
    {
        for(const auto& sh: ships) this->shipsList.insert({sh.first,sh.second});
    }
}