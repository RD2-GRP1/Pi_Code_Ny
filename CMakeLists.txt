cmake_minimum_required(VERSION 3.5)

project(Forbindelse_Til_UR LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Så den kan finde network pakken, til at kunne socket
find_package(Qt5 COMPONENTS Network REQUIRED)

# Tilføj filer til qt
add_executable(Forbindelse_Til_UR main.cpp)

# linke den til libery
target_link_libraries(Forbindelse_Til_UR Qt5::Network)
