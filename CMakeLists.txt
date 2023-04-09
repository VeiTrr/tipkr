cmake_minimum_required(VERSION 3.24)
project(tipkr)

set(CMAKE_CXX_STANDARD 17)

add_executable(tipkr main.cpp)

set(SDL_STATIC ON)
set(SDL_SHARED ON)
set(SDL2_DIR "C:/prg/SDL/x86_64-w64-mingw32/lib/cmake/SDL2")
find_package(SDL2 REQUIRED)

target_link_libraries(tipkr SDL2::SDL2main SDL2::SDL2-static)




