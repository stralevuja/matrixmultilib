cmake_minimum_required(VERSION 4.2)
project(matrixlib C)

set(CMAKE_C_STANDARD 11)

add_library(matrixlib STATIC library.c)
