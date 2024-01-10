
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-01 LANGUAGES CXX)

include_directories(../)

add_executable(01_add_item 01_add_item.cc ../Sales_data.cc)
add_executable(02_add_item2 02_add_item2.cc ../Sales_data.cc)
add_executable(03_buf 03_buf.cc)
add_executable(04_clearIO 04_clearIO.cc)
add_executable(05_fileIO 05_fileIO.cc)
add_executable(06_sstream 06_sstream.cc)
# add_executable(07_mk_plural 07_mk_plural.cc)
# add_executable(08_ref-fcn 08_ref-fcn.cc)
# add_executable(09_refparms 09_refparms.cc)
# add_executable(10_refret-ex 10_refret-ex.cc)
# add_executable(11_reset 11_reset.cc)
# add_executable(12_stl_arr_fcns 12_stl_arr_fcns.cc)
# add_executable(13_use_mk_plural 13_use_mk_plural.cc)
# add_executable(14_usefcnptr 14_usefcnptr.cc)
# add_executable(15_wdebug 15_wdebug.cc)
