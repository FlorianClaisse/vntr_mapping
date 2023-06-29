cmake_minimum_required(VERSION 3.4)
project(vntr_mapping CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/csv-parser)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/csv-parser/include)

add_executable(vntr_mapping main.cpp)

target_link_libraries(vntr_mapping csv)
