cmake_minimum_required(VERSION 3.5)

project(URClient)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Network REQUIRED) # Tilføj "Network" her

add_executable(URClient main.cpp)

target_link_libraries(URClient Qt5::Widgets Qt5::Network) # Tilføj "Network" her
