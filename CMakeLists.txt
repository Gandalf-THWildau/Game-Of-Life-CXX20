cmake_minimum_required(VERSION 3.16)
project(game_of_life CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(game_of_life
    src/main.cpp
    external/glad/src/glad.c
)

set_source_files_properties(external/glad/src/glad.c PROPERTIES LANGUAGE CXX)

target_include_directories(game_of_life PRIVATE
    external/glad/include
)

target_link_libraries(game_of_life
    OpenGL::GL
    glfw
)