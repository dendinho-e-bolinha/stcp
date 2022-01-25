#include "pathfinding.h"

#include "harversine.h"
#include "graphs/least_distance.h"

using namespace std;

bool Pathfinding::has_line(string code) const {
    return line_positions.contains(code);
}

bool Pathfinding::has_bus_stop(string code) const {
    return bus_stop_positions.contains(code);
}

void Pathfinding::add_line(string code, Direction dir, string name) {
    if (has_line(code)) return;

    lines.push_back({ code, dir, name });
    line_positions.insert({ code + '/' + to_string(dir), lines.size() - 1 });
}

void Pathfinding::add_bus_stop(string code, string name, string zone, pair<double, double> point) {
    if (has_bus_stop(code)) return;

    bus_stops.push_back({ code, name, zone, point });
    bus_stop_positions.insert({ code, bus_stops.size() - 1 });
}

void Pathfinding::add_line_stop(string line_code, Direction dir, string bus_stop_code) {
    if (!has_line(line_code) || !has_bus_stop(bus_stop_code)) return;

    int line_index = line_positions.at(line_code + '/' + to_string(dir));
    Line &line = lines.at(line_index);

    int bus_stop_index = bus_stop_positions.at(bus_stop_code);
    line.stops.push_back(bus_stop_index);
}

list<Node> Pathfinding::get_least_distance_path(string start, string end, double max_distance) {
    LeastDistanceGraph graph();
}
