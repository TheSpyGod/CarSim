cmake_minimum_required(VERSION 3.16)
project(CarSim)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)

file(GLOB_RECURSE ALL_SOURCES "src/*.cpp")

# Add your executable
add_executable(CarSim main.cpp ${ALL_SOURCES})
target_link_libraries(CarSim PRIVATE raylib)

file(GLOB_RECURSE ALL_SOURCES "src/*.cpp")
target_include_directories(CarSim PRIVATE src)
