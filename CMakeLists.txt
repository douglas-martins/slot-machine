cmake_minimum_required(VERSION 3.10)
project(slot_machine)

set(CMAKE_CXX_STANDARD 11)

add_executable(slot_machine main.cpp headers/bet.h cpp/bet.cpp headers/symb.h cpp/symb.cpp headers/inputReaders.h cpp/inputReaders.cpp headers/generateResults.h cpp/generateResults.cpp headers/defaultIncludes.h cpp/screen.cpp headers/screen.h)