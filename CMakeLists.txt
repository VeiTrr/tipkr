cmake_minimum_required(VERSION 3.24)
project(tipkr)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(tipkr WIN32 main.cpp Game.cpp Game.h Snake.cpp Snake.h Food.cpp Food.h Score.cpp Score.h Input.cpp Input.h Renderer.cpp Renderer.h data/resources.rc)
    else()
    add_executable(tipkr main.cpp Game.cpp Game.h Snake.cpp Snake.h Food.cpp Food.h Score.cpp Score.h Input.cpp Input.h Renderer.cpp Renderer.h data/resources.rc)
endif ()

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/prg/SFML/lib/cmake/SFML")
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(tipkr sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
set(CMAKE_EXE_LINKER_FLAGS -static)




