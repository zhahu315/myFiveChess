cmake_minimum_required(VERSION 3.17)
project(myFiveChess)

set(CMAKE_CXX_STANDARD 14)

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)

aux_source_directory(src SRC_LIST)

add_executable(myFiveChess ${SRC_LIST} include/ai.h src/ai.cpp)
