cmake_minimum_required(VERSION 3.15)
project(Sudoku)
set(SOURCES
    ./main.cpp
    ./sudoku.cpp
    ./grid.cpp
)
set(CMAKE_CXX_STANDARD 20)
add_executable(${PROJECT_NAME} ${SOURCES})
