cmake_minimum_required(VERSION 3.24)
project(tipkr)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_PATH "${CMAKE_SOURCE_DIR}\\libs\\SDL2-2.26.4\\x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SDL2_TTF_PATH "${CMAKE_SOURCE_DIR}\\libs\\SDL2_ttf-2.20.2\\x86_64-w64-mingw32")
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIRS})

add_executable(tipkr main.cpp Game.cpp Game.h Snake.cpp Snake.h Food.cpp Food.h Input.cpp Input.h Score.cpp Score.h Renderer.cpp Renderer.h)


target_link_libraries(tipkr ${SDL2_LIBRARIES})
target_link_libraries(tipkr ${SDL2_TTF_LIBRARIES})
