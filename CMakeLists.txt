cmake_minimum_required(VERSION 3.24)
project(tipkr)

set(CMAKE_CXX_STANDARD 17)

add_executable(tipkr main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/prg/SFML/lib/cmake/SFML")
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(tipkr sfml-system sfml-window sfml-graphics sfml-network sfml-audio)





