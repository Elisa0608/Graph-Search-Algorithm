cmake_minimum_required(VERSION 3.10)

project(GraphSearchProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

add_executable(graph_search 
    main.cpp
    src/Graph.cpp 
    src/Algorithms.cpp
)