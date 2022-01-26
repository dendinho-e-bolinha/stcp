cmake_minimum_required(VERSION 3.21)
project(FEUP_AED_STCP)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)


add_executable(stcp
    main.cpp
    src/graphs/least_bus_changes.cpp
    src/graphs/least_distance.cpp
    src/graphs/least_money_spent.cpp
    src/graphs/least_stops.cpp
    src/dataset.cpp
    src/harversine.cpp
    src/names.cpp
    src/pathfinding.cpp
)
