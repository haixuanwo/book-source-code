
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-01 LANGUAGES CXX)

include_directories(../)

add_executable(01_add_item 01_add_item.cc ../Sales_data.cc)
add_executable(02_avg_price 02_avg_price.cc ../Sales_data.cc)
add_executable(03_useAccount 03_useAccount.cc Account.cc)
add_executable(04_useDebug 04_useDebug.cc Debug.cc)
add_executable(05_useScreen 05_useScreen.cc)
