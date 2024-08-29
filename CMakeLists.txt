#FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 20)

option(ASIO_USE_CPM "Download Asio with CPM instead of FetchContent" OFF)
option(
  ASIO_CPM_FETCHCONTENT_COMPAT
  "Should asio be declared with FetchContent functions to be compatible. This doesn't not allow CPM cache to work."
  ON
)

project("Fleet Battle"
        VERSION "${VERSION}"
        DESCRIPTION "Yet another fleet battle implementation for excercise purposes"
        HOMEPAGE_URL "https://github.com/antlampas/FleetBattle"
        LANGUAGES "CXX"
)

include(FetchContent)

include_directories(include)

FetchContent_Declare(
  asiocmake
  GIT_REPOSITORY "https://github.com/OlivierLDff/asio.cmake"
  GIT_TAG        "main"
)
FetchContent_MakeAvailable(asiocmake)

add_subdirectory(src ${CMAKE_BUILD_TYPE})