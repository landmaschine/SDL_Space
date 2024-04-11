cmake_minimum_required(VERSION 3.28.0)
project(Space)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setzen Sie den Pfad zu SDL2 und SDL2_image auf Ihrem System.
set(SDL2_DIR "/usr/include/SDL2")
set(SDL2_IMAGE_DIR "/usr/include/SDL2")

# Fügen Sie das Quellverzeichnis hinzu
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
file(GLOB_RECURSE SOURCE_FILES "${SOURCE_DIR}/src/*.cpp" "${SOURCE_DIR}/Engine/*.cpp")

# Fügen Sie das Include-Verzeichnis hinzu
include_directories("${SDL2_DIR}" "${SDL2_IMAGE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/Engine")

# Fügen Sie das Ausführbare hinzu
add_executable(Space ${SOURCE_FILES})

# Verknüpfen Sie SDL2 und SDL2_image
target_include_directories(Space PRIVATE "${SDL2_DIR}" "${SDL2_IMAGE_DIR}")
target_link_libraries(Space PRIVATE SDL2 SDL2main SDL2_image)