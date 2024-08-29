#FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

get_directory_property(MYDEFS COMPILE_DEFINITIONS)

add_subdirectory(agent         agent         )
add_subdirectory(board         board         )
add_subdirectory(game          game          )
add_subdirectory(matchMaster   matchMaster   )
add_subdirectory(opponentBoard opponentBoard )
add_subdirectory(player        player        )
add_subdirectory(playerBoard   playerBoard   )
add_subdirectory(ships         ships         )
add_subdirectory(utilities     utilities     )

add_executable(fleetBattle main.cpp)

target_link_libraries(fleetBattle PUBLIC
                      agent
                      board
                      game
                      matchMaster
                      opponentBoard
                      player
                      playerBoard
                      ships
                      utilities
                     )

target_link_libraries(fleetBattle PRIVATE asio::asio)