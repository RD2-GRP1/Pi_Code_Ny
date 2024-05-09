cmake_minimum_required(VERSION 3.5)

project(Semesterprojekt2 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core Quick Sql)
#find_package(QT${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
#if(NOT Qt5_FOUND)
#    message(FATAL_ERROR "Qt5 not found!")
#endif()

add_executable(Semesterprojekt2 main.cpp database.cpp database.h motorkontrol.h motorkontrol.cpp)

link_directories("/usr/lib")

target_link_libraries(Semesterprojekt2 Qt5::Core Qt5::Quick Qt5::Sql wiringPi)
target_link_libraries(Semesterprojekt2 wiringPi)

include(GNUInstallDirs)
install(TARGETS Semesterprojekt2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
