cmake_minimum_required(VERSION 3.16)
project(game_of_life CXX)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
    -fcolor-diagnostics
    -fansi-escape-codes
    -g
    -Wall
    -static
    -stdlib=libc++
)

add_link_options(
    -static
    -stdlib=libc++
    -lc++
    -lc++abi
    -static-libgcc
)

add_executable(game_of_life main.cpp)