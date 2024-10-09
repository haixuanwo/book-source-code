
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-01 LANGUAGES CXX)

include_directories(../)

add_executable(01_erasemap 01_erasemap.cc)
add_executable(02_map1 02_map1.cc)
add_executable(03_multimap 03_multimap.cc)
add_executable(04_pair 04_pair.cc)
add_executable(05_restricted_count 05_restricted_count.cc)
add_executable(06_setOps 06_setOps.cc)
add_executable(07_unorderedWordCount 07_unorderedWordCount.cc)
add_executable(08_wcEx 08_wcEx.cc)
add_executable(09_word_count 09_word_count.cc)
add_executable(10_word_transform 10_word_transform.cc)
