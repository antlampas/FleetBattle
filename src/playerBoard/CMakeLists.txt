#FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

get_directory_property(MYDEFS COMPILE_DEFINITIONS)

add_library(playerBoard SHARED
            applyShipsLayer.cpp
            checkOverlappingShips.cpp
            checkShipSunk.cpp
            deployShips.cpp
            drawDeployedShipsOnBoard.cpp
            getBoardStatus.cpp
            getSquareStatus.cpp
            hit.cpp
            initiateDestroyedShips.cpp
            initiateShipsLayer.cpp
            isSquareAlreadyHit.cpp
            playerBoard.cpp
            setSquareStatus.cpp
           )