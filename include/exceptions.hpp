/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

 #ifndef EXCEPTIONS_HPP
 #define EXCEPTIONS_HPP

#include <exception>

namespace fleetBattle
{
    class unknownError                  : public std::exception {};
    class boardConstructionError        : public std::exception {};
    class playerConstructionError       : public std::exception {};
    class matchMasterConstructionError  : public std::exception {};
    class gameConstructionError         : public std::exception {};
    class shipNotValid                  : public std::exception {};
    class coordinatesNotValid           : public std::exception {};
    class notHorizontalOrVertical       : public std::exception {};
    class squareAlreadyHit              : public std::exception {};
    class notImplemented                : public std::exception {};
}

#endif