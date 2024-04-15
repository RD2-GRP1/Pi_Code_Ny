cmake_minimum_required(VERSION 3.5)

project(Semesterprojekt2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Semesterprojekt2 main.cpp)

link_directories("/usr/lib")

target_link_libraries(Semesterprojekt2 wiringPi)

install(TARGETS Semesterprojekt2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
