cmake_minimum_required(VERSION 3.5)

project(Semesterprojekt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt5 REQUIRED COMPONENTS  Core )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Semesterprojekt main.cpp)

link_directories("/usr/lib")

target_link_directories(Semesterprojekt Qt5::Core wiringPi)


include(GNUInstallDirs)
install(TARGETS Semesterprojekt
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
