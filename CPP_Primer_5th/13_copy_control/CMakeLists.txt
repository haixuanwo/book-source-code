
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-01 LANGUAGES CXX)

include_directories(../)

add_executable(01_copyNoMove 01_copyNoMove.cc)
add_executable(02_FolderMain 02_FolderMain.cc Folder.cc)
add_executable(03_HasPtrlCount 03_HasPtrlCount.cc)
add_executable(04_HasPtrValueLike 04_HasPtrValueLike.cc)
add_executable(05_moveHP 05_moveHP.cc)
add_executable(06_serial 06_serial.cc)
add_executable(07_StrFolderMain 07_StrFolderMain.cc StrFolder.cc String.cc)
add_executable(08_substr 08_substr.cc)
add_executable(09_useStrVec 09_useStrVec.cc StrVec.cc)
