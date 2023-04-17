cmake_minimum_required(VERSION 3.26)
project(TextAdventure C)

set(CMAKE_C_STANDARD 11)

FILE(GLOB Source Source/*)

add_executable(TextAdventure main.c WorldDataFactory.c CommandListFactory.c ${Source} Source/s_functions.h Source/s_functions.c)