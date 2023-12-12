
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-01 LANGUAGES CXX)

include_directories(../)

add_executable(01_add_using 01_add_using.cc)
add_executable(02_arrayScores 02_arrayScores.cc)
add_executable(03_cctype 03_cctype.cc)
add_executable(04_char_repl 04_char_repl.cc)
add_executable(05_cstring_hdr 05_cstring_hdr.cc)
add_executable(06_getline 06_getline.cc)
add_executable(07_hexify 07_hexify.cc)
add_executable(08_multidim 08_multidim.cc)
add_executable(09_ptr_traversal2 09_ptr_traversal2.cc)
add_executable(10_square 10_square.cc)
add_executable(11_strcompare 11_strcompare.cc)

add_executable(12_string_add 12_string_add.cc)
add_executable(13_string_io 13_string_io.cc)
add_executable(14_string_io2 14_string_io2.cc)
add_executable(15_string_size 15_string_size.cc)
add_executable(16_string_size2 16_string_size2.cc)
add_executable(17_string_size3 17_string_size3.cc)

add_executable(18_vec_decls 18_vec_decls.cc)
add_executable(19_vecScores 19_vecScores.cc)
add_executable(20_vecString2 20_vecString2.cc)
add_executable(21_vecSubs 21_vecSubs.cc)
add_executable(22_word_echo 22_word_echo.cc)
