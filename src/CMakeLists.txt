#FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

get_directory_property(MYDEFS COMPILE_DEFINITIONS)

add_subdirectory(board board)
add_subdirectory(opponentBoard opponentBoard)
add_subdirectory(matchMaster matchMaster)
add_subdirectory(playerBoard playerBoard)
add_subdirectory(ships ships)

add_executable(fleetBattle main.cpp)

target_link_libraries(fleetBattle PUBLIC ships board playerBoard matchMaster)