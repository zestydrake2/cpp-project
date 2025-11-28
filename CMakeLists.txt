cmake_minimum_required(VERSION 3.10)
project(PhysicsDemo)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(raylib)  
include_directories(include)

file(GLOB SOURCES "src/*")


add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} raylib)

