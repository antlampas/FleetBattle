/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

namespace fleetBattle
{
    namespace board
    {
        #ifndef BOARD_HPP
        #define BOARD_HPP

        #include <array>
        #include <vector>
        #include <utility>
        #include <string>
        #include <map>
        #include <exception>

        #ifdef TESTBOARD
        #define private public
        #endif

        using coordinates_t             = std::string;
        using decodedCoordinateSingle_t = unsigned short int;
        using decodedCoordinatesPair_t  = std::pair<decodedCoordinateSingle_t,decodedCoordinateSingle_t>;
        using squareStatus_t            = char;
        using shootStatus_t             = unsigned short int;
        using board_t                   = std::array<std::array<squareStatus_t,10>,10>;
        using shipStatus_t              = std::array<squareStatus_t,10>;
        using deployedShips_t           = std::vector<std::pair<std::string,std::string>>;
        using destroyedShips_t          = std::vector<std::string>;

        #ifndef shipSize_t
        using shipSize_t  = unsigned short int;
        #endif
        #ifndef shipsList_t
        using shipsList_t = std::map<std::string,unsigned short int>;
        #endif

        class unknownError            : public std::exception {};
        class boardConstructionError  : public std::exception {};
        class shipNotValid            : public std::exception {};
        class coordinatesNotValid     : public std::exception {};
        class notHorizontalOrVertical : public std::exception {};
        class squareAlreadyHit        : public std::exception {};
        class notImplemented          : public std::exception {};

        class board
        {
            /*
            * U = unknown
            * S = ship square
            * W = water
            * s = ship square hit
            * w = water square hit
            */
            protected:
            board_t Board;
            protected:
            bool                     isCoordinatesValid(coordinates_t);
            decodedCoordinatesPair_t decodeCoordinates(coordinates_t);
            virtual bool             hit(coordinates_t)                            = 0; 
            public:
            enum shootReturnCodes    {HIT,MISSED,SQUARE_ALREADY_HIT};
            public:
            board();
            virtual ~board();
            virtual board_t          getBoardStatus()                              = 0;
            virtual squareStatus_t   getSquareStatus(coordinates_t)                = 0;
            virtual bool             isSquareAlreadyHit(coordinates_t)             = 0;
            virtual shootStatus_t    shoot(coordinates_t)                          = 0;
            virtual squareStatus_t   setSquareStatus(coordinates_t,squareStatus_t) = 0;
        };

        #endif
    }
}