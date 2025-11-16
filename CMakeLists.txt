cmake_minimum_required(VERSION 3.15)
project(GLibHelloWorld)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(glib REQUIRED CONFIG)

add_executable(hello_glib main.cpp)
target_link_libraries(hello_glib glib::glib)
