
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-01 LANGUAGES CXX)

include_directories(../)

add_executable(01_arrRet 01_arrRet.cc)
add_executable(02_count-calls 02_count-calls.cc)
add_executable(03_errMsg_initList 03_errMsg_initList.cc)
add_executable(04_fact 04_fact.cc LocalMath.cc)
add_executable(05_mainmath 05_mainmath.cc LocalMath.cc)
add_executable(06_mainret 06_mainret.cc)
add_executable(07_mk_plural 07_mk_plural.cc)
add_executable(08_ref-fcn 08_ref-fcn.cc)
add_executable(09_refparms 09_refparms.cc)
add_executable(10_refret-ex 10_refret-ex.cc)
add_executable(11_reset 11_reset.cc)
add_executable(12_stl_arr_fcns 12_stl_arr_fcns.cc)
add_executable(13_use_mk_plural 13_use_mk_plural.cc)
add_executable(14_usefcnptr 14_usefcnptr.cc)
add_executable(15_wdebug 15_wdebug.cc)
