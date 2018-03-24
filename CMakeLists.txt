cmake_minimum_required(VERSION 3.9)
project(pprocess)

set(CMAKE_CXX_STANDARD 11)
add_definitions(-I/${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE header_files "src/*.h" "src/*.hh")
file(GLOB_RECURSE source_files "src/*.cpp" "src/*.cc")

set(HEADER_FILES ${header_files})
set(SOURCE_FILES ${source_files})

add_executable(pprocess ${SOURCE_FILES} ${HEADER_FILES})
