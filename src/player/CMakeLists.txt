#FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

get_directory_property(MYDEFS COMPILE_DEFINITIONS)

add_library(player SHARED
            agentInput.cpp
            checkOpponentBoard.cpp
            checkOwnBoard.cpp
            functor.cpp
            getSquareStatus.cpp
            player.cpp
            setSquareStatus.cpp
            shoot.cpp
           )