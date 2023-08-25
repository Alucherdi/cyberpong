cmake_minimum_required(VERSION 3.23)
project(nc)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories("src")
file(GLOB_RECURSE SOURCES src/*.cpp)

include_directories("lib/raylib/include")
link_directories("lib/raylib/lib")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} raylib)
