/*
 *
 * FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/
 *
 */

#ifndef PLAYERBOARD_HPP
#define PLAYERBOARD_HPP

#include "types.hpp"
#include "exceptions.hpp"
#include "board.hpp"
#include "ships.hpp"

#include <iterator>



#ifdef TESTPLAYERBOARD
#define private public
#endif

namespace fleetBattle
{
    class playerBoard final : public board
    {
        private:
        deployedShips_t        deployedShips;
        shipsSquaresList_t     deployedShipsMap;
        destroyedShips_t       destroyedShips;
        board_t                shipsLayer;
        
        private:
        board_t                applyShipsLayer();
        bool                   initiateShipsLayer();
        bool                   checkOverlappingShips(deployedShips_t);
        bool                   initiateDestroyedShips();
        bool                   deployShips(deployedShips_t);
        bool                   drawDeployedShipsOnBoard();
        void                   checkShipSunk(coordinates_t);
        
        protected:
        virtual bool           hit(coordinates_t)                            override final;
        virtual board_t        _getBoardStatus()                             override final;
        
        public:
        virtual squareStatus_t getSquareStatus(coordinates_t)                override final;
        virtual bool           isSquareAlreadyHit(coordinates_t)             override final;
        virtual squareStatus_t setSquareStatus(coordinates_t,squareStatus_t) override final;

        public:
        playerBoard() = delete;
        playerBoard(deployedShips_t);
        board_t getBoardStatus();
    };
}
#endif