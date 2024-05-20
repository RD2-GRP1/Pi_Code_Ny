cmake_minimum_required(VERSION 3.5)

project(Semesterprojekt2 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS Core Quick Sql Widgets Network) # Tilføj "Network" her
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
#find_package(Qt5 COMPONENTS Widgets Network REQUIRED)
#find_package(Boost REQUIRED)

#find_path(UR_RTDE_INCLUDE_DIR NAMES ur_rtde/rtde_control_interface.h)
#find_library(UR_RTDE_LIBRARY NAMES ur_rtde)

#include_directories(${UR_RTDE_INCLUDE_DIR})
#include_directories(${UR_RTDE_LIBRARY})

add_executable(Semesterprojekt2 main.cpp database.cpp database.h motorkontrol.h motorkontrol.cpp UR5.h UR5.cpp)

link_directories("/usr/lib")




target_link_libraries(Semesterprojekt2 Qt5::Core Qt5::Quick Qt5::Sql Qt5::Widgets Qt5::Network wiringPi)

#target_link_libraries(Semesterprojekt2 wiringPi)

include(GNUInstallDirs)
install(TARGETS Semesterprojekt2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})



