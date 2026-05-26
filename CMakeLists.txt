cmake_minimum_required(VERSION 3.23)

project(Chaos)

add_executable(Chaos source/main_chaos.cpp)

target_include_directories(Chaos PUBLIC source/fonctions)
target_compile_options(Chaos PUBLIC -O3 -march=native -flto)