cmake_minimum_required(VERSION 3.27)
project(Linked_lists_in_C C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(main
        list.jlemahie.h
        main.c
        movie.jlemahie.h
        movie.jlemahie.c
        list.jlemahie.c)

add_executable(test
        list.jlemahie.h
        movie.jlemahie.h
        movie.jlemahie.c
        list.jlemahie.c
        list-unit-tests.c)

