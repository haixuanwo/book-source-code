
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-01 LANGUAGES CXX)

include_directories(../)

add_executable(01_bitfields 01_bitfields.cc)

add_executable(02_calc 02_calc.cc)


add_executable(03_dyn_cast 03_dyn_cast.cc)
add_executable(04_enum_match 04_enum_match.cc)
add_executable(05_enum 05_enum.cc)

add_executable(06_memFN_bind 06_memFN_bind.cc)
add_executable(07_tok2 07_tok2.cc)

add_executable(08_typeid 08_typeid.cc)
add_executable(09_useScreen.cc 09_useScreen Screen)
