cmake_minimum_required(VERSION 3.5)

project(URClient)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Network REQUIRED) # Tilføj "Network" her

add_executable(Semesterprojekt2 main.cpp database.cpp database.h motorkontrol.h motorkontrol.cpp UR.h UR.cpp)

link_directories("/usr/lib")

target_link_libraries(Semesterprojekt2 Qt5::Core Qt5::Quick Qt5::Sql wiringPi)
target_link_libraries(Semesterprojekt2 wiringPi)

include(GNUInstallDirs)
install(TARGETS Semesterprojekt2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

add_executable(URClient main.cpp)

target_link_libraries(URClient Qt5::Widgets Qt5::Network) # Tilføj "Network" her

