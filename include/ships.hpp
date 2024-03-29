/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef SHIPS_HPP
#define SHIPS_HPP

#include <string>
#include <vector>
#include <map>
#include <utility>

#include "types.hpp"

#ifdef TESTSHIPS
#define private public
#endif

namespace fleetBattle
{


    class ships final
    {
        private:
        shipsList_t shipsList;
        
        public:
        const shipsList_t& publicShipsList;
        ships();
        ships(shipsList_t);
        void addShip(std::pair<std::string,int>);
        void removeShip(std::string);
    };
}
#endif