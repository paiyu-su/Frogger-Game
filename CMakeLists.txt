cmake_minimum_required(VERSION 3.15)

project(Frogger)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(
    Frogger

    src/main.cpp
    src/Game.cpp
    src/Car.cpp
    src/Frog.cpp
    src/Coin.cpp
 "include/GameObject.h")