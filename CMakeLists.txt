cmake_minimum_required(VERSION 3.10)
project(PhysicsDemo)

set(CMAKE_CXX_STANDARD 17)

# Tell CMake where the raylib folder is
add_subdirectory(raylib)  # builds raylib inside your project

include_directories(include)

file(GLOB SOURCES "src/*")

# Add your main executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link Raylib to your executable
target_link_libraries(${PROJECT_NAME} raylib)

# add_custom_command(TARGET PhysicsDemo POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#         ${CMAKE_SOURCE_DIR}/assets
#         $<TARGET_FILE_DIR: PhysicsDemo>/assets)
