cmake_minimum_required(VERSION 3.23)

project(Chaos)

add_executable(Chaos)

target_sources(Chaos PUBLIC
    source/main_chaos.cpp)
target_include_directories(Chaos PUBLIC source/fonctions)