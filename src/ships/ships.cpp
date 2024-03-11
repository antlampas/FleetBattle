/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include "ships.hpp"

ships::ships()
{
    this->shipsList.insert({"Carrier",6});
    this->shipsList.insert({"Cruiser",5});
    this->shipsList.insert({"Destroyer",4});
    this->shipsList.insert({"Frigate",3});
    this->shipsList.insert({"Corvette",2});
}

ships::ships(std::map<std::string,int> s)
{
    for(const auto& sh: s) this->shipsList.insert({sh.first,sh.second});
}