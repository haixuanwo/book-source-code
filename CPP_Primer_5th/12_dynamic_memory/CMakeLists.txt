
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-01 LANGUAGES CXX)

include_directories(../)

add_executable(01_allocPtr 01_allocPtr.cc)
add_executable(02_allocSP 02_allocSP.cc)
add_executable(03_oknew 03_oknew.cc)
add_executable(04_querymain 04_querymain.cc TextQuery.cc)
add_executable(05_unique 05_unique.cc)
add_executable(06_UP 06_UP.cc)
add_executable(07_usealloc 07_usealloc.cc)
add_executable(08_usealloc2 08_usealloc2.cc)
add_executable(09_useBlob 09_useBlob.cc)
add_executable(10_weak 10_weak.cc)
