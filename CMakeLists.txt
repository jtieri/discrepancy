cmake_minimum_required(VERSION 3.13)
project(discrepancy)

set(CMAKE_CXX_STANDARD 17)

add_executable(discrepancy main.cpp)
target_link_libraries(${PROJECT_NAME} stdc++fs)