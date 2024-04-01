/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

 namespace fleetBattle
 {
    agent::agent(std::shared_ptr<std::mutex> mutex,std::shared_ptr<command_t> command) : mutex(mutex),command(command){}
 }