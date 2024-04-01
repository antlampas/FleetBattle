/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#include <memory>
#include <iostream>
#include <mutex>
#include "types.hpp"

 namespace fleetBattle
 {
    class agent final
    {
        private:
        std::shared_ptr<std::mutex> mutex;

        public:
        agent();
        void operator()();
    }
 }