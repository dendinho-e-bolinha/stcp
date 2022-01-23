cmake_minimum_required(VERSION 3.21)
project(FEUP_AED_STCP)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)


add_executable(stcp
    main.cpp
    src/dataset.cpp
    src/dijkstra.cpp
    src/harversine.cpp
    src/interact.cpp
)
