#pragma once

#include <string>
#include <optional>
#include <list>
#include <unordered_map>
#include <vector>
#include "direction.h"

class Pathfinding {

    struct Node {
        std::string stop;
        std::optional<std::list<std::string>> lines;
    };

    struct Line {
        std::string code;
        Direction dir;

        std::string name;
        std::list<int> stops;
    };

    struct BusStop {
        std::string code;

        std::string name;
        std::string zone;
        std::pair<double, double> point;
    };

    std::unordered_map<std::string, int> bus_stop_positions;
    std::unordered_map<std::string, int> line_positions;

    std::vector<Line> lines;
    std::vector<BusStop> bus_stops;

    public:
        bool has_line(std::string code) const;
        bool has_bus_stop(std::string code) const;

        void add_line(std::string code, Direction dir, std::string name);
        void add_bus_stop(std::string code, std::string name, std::string zone, std::pair<double, double> point);
        void add_line_stop(std::string line_code, Direction dir, std::string bus_stop_code);

        std::list<Node> get_least_distance_path(std::string start, std::string end, double max_distance);
};

