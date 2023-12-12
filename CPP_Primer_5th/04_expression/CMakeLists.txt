
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-01 LANGUAGES CXX)

include_directories(../)

add_executable(01_arith-ex 01_arith-ex.cc)
add_executable(02_arraysizeof 02_arraysizeof.cc)
add_executable(03_cond 03_cond.cc)
add_executable(04_incr 04_incr.cc)
add_executable(05_int-div 05_int-div.cc)
add_executable(06_oofe 06_oofe.cc)
add_executable(07_overflow 07_overflow.cc)
add_executable(08_prec 08_prec.cc)
add_executable(09_shit-prec 09_shit-prec.cc)
add_executable(10_sizeof_pgm 10_sizeof_pgm.cc)
add_executable(11_unaryOps 11_unaryOps.cc)

add_executable(12_vec_init 12_vec_init.cc)
# add_executable(13_string_io 13_string_io.cc)
# add_executable(14_string_io2 14_string_io2.cc)
# add_executable(15_string_size 15_string_size.cc)
# add_executable(16_string_size2 16_string_size2.cc)
# add_executable(17_string_size3 17_string_size3.cc)

# add_executable(18_vec_decls 18_vec_decls.cc)
# add_executable(19_vecScores 19_vecScores.cc)
# add_executable(20_vecString2 20_vecString2.cc)
# add_executable(21_vecSubs 21_vecSubs.cc)
# add_executable(22_word_echo 22_word_echo.cc)
