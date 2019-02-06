cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(darray LANGUAGES C)
add_library(darray "src/darray.c")
target_include_directories(darray PUBLIC "src/")
target_compile_options(darray
  PUBLIC "-std=c90"
  PUBLIC "-pedantic-errors"
  PUBLIC "-Wall"
  PUBLIC "-Wconversion"
  )
