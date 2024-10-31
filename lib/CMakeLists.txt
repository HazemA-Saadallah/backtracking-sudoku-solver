cmake_minimum_required(VERSION 3.10)
add_library(sudoku STATIC sudoku.cxx)
target_include_directories(sudoku PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
