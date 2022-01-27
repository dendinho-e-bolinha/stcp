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

        int first_bus_stop = -1;
    };

    struct BusStop {
        std::string code;

        std::string name;
        std::string zone;
        std::pair<double, double> point;

        std::unordered_map<std::string, int> destinations;
    };

    std::unordered_map<std::string, int> bus_stop_positions;
    std::unordered_map<std::string, int> line_positions;

    std::vector<Line> lines;
    std::vector<BusStop> bus_stops;

    std::string get_line_key(std::string code, Direction dir) const;

    int get_last_bus_stop(std::string code, Direction dir) const;
    std::list<int> get_bus_stops(std::string code, Direction dir) const;

    public:
        bool has_line(std::string code, Direction dir) const;
        bool has_bus_stop(std::string code) const;

        void add_line(std::string code, Direction dir, std::string name);
        void add_bus_stop(std::string code, std::string name, std::string zone, std::pair<double, double> point);
        void add_line_stop(std::string line_code, Direction dir, std::string bus_stop_code);
        void add_on_foot_segments(double max_distance);

        std::list<Node> get_least_distance_path(std::string start, std::string end);
        std::list<Node> get_least_stops_path(std::string start, std::string end);
        std::list<Node> get_least_money_spent_path(std::string start, std::string end);
};

