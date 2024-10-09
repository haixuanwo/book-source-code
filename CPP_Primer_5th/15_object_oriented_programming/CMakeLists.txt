
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-01 LANGUAGES CXX)

include_directories(../)

add_executable(01_and_orQueryTest 01_and_orQueryTest.cc Query.cc get_print.cc ../TextQuery.cc)
add_executable(02_andQueryTest 02_andQueryTest.cc Query.cc get_print.cc ../TextQuery.cc)
add_executable(03_Basket_main 03_Basket_main.cc Basket.cc Quote.cc)
add_executable(04_sample 04_sample.cc Quote.cc)
add_executable(05_scope 05_scope.cc)
add_executable(06_useQuote 06_useQuote.cc Quote.cc)
add_executable(07_vecBasket 07_vecBasket.cc Quote.cc)
add_executable(08_virtualsNscope 08_virtualsNscope.cc)
add_executable(09_wordQueryTest 09_wordQueryTest.cc Quote.cc get_print.cc ../TextQuery.cc)
