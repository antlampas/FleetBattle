#FALP Fleet Battle © 2024 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 20)

project("Fleet Battle"
        VERSION "${VERSION}"
        DESCRIPTION "Yet another fleet battle implementation for excercise purposes"
        HOMEPAGE_URL "https://github.com/antlampas/FleetBattle"
        LANGUAGES "CXX"
)

include(FetchContent)

FetchContent_Declare(boost
  GIT_REPOSITORY "https://github.com/boostorg/boost.git"
  GIT_TAG        "master"
)
FetchContent_MakeAvailable(boost)

include_directories(include)

FILE(GLOB children RELATIVE ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR}/_deps/boost-src/libs/*)
FOREACH(child ${children})
  IF(IS_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${child}/include)
    include_directories(${CMAKE_CURRENT_BINARY_DIR}/${child}/include)
  ENDIF()
  IF(IS_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${child})
  FILE(GLOB subchildren RELATIVE ${CMAKE_CURRENT_BINARY_DIR}/${child} ${CMAKE_CURRENT_BINARY_DIR}/${child}/*)
    FOREACH(subchild ${subchildren})
      IF(IS_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${child}/${subchild}/include)
        include_directories(${CMAKE_CURRENT_BINARY_DIR}/${child}/${subchild}/include)
      ENDIF()
    ENDFOREACH()
  ENDIF()
ENDFOREACH()

add_subdirectory(src ${CMAKE_BUILD_TYPE})