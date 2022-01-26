#include "pathfinding.h"

#include <stdexcept>
#include <iostream>
#include "graphs/least_distance.h"
#include "harversine.h"
#include "names.h"

using namespace std;

bool Pathfinding::has_line(string code, Direction dir) const {
    return line_positions.contains(get_line_key(code, dir));
}

bool Pathfinding::has_bus_stop(string code) const {
    return bus_stop_positions.contains(code);
}

string Pathfinding::get_line_key(string code, Direction dir) const {
    return code + '/' + to_string(dir);
}

list<int> Pathfinding::get_bus_stops(string code, Direction dir) const {
    if (!has_line(code, dir)) return {};

    string line_key = get_line_key(code, dir);
    int current = lines.at(line_positions.at(line_key)).first_bus_stop;
    if (current == -1) return {};

    list<int> stops;
    while (stops.front() != current && bus_stops.at(current).destinations.contains(line_key)) {
        stops.push_back(current);
        current = bus_stops.at(current).destinations.at(line_key);
    }

    stops.push_back(current);
    return stops;
}

int Pathfinding::get_last_bus_stop(string code, Direction dir) const {
    return get_bus_stops(code, dir).back();
}

void Pathfinding::add_line(string code, Direction dir, string name) {
    if (has_line(code, dir)) return;

    lines.push_back({ code, dir, name });
    line_positions.insert({ get_line_key(code, dir), lines.size() - 1 });
}

void Pathfinding::add_bus_stop(string code, string name, string zone, pair<double, double> point) {
    if (has_bus_stop(code)) return;

    bus_stops.push_back({ code, name, zone, point });
    bus_stop_positions.insert({ code, bus_stops.size() - 1 });
}

void Pathfinding::add_line_stop(string line_code, Direction dir, string bus_stop_code) {
    if (!has_line(line_code, dir) || !has_bus_stop(bus_stop_code)) return;

    int line_index = line_positions.at(get_line_key(line_code, dir));
    Line &line = lines.at(line_index);

    int bus_stop_index = bus_stop_positions.at(bus_stop_code);
    if (line.first_bus_stop == -1) {
        line.first_bus_stop = bus_stop_index;
        return;
    }

    int last_stop = get_last_bus_stop(line_code, dir);
    bus_stops.at(last_stop).destinations.insert({ get_line_key(line_code, dir), bus_stop_index });
}

void Pathfinding::add_on_foot_segments(double max_distance) {
    for (int i = 0; i < bus_stops.size(); i++) {
        for (int j = i + 1; j < bus_stops.size(); j++) {
            BusStop &stop1 = bus_stops[i];
            BusStop &stop2 = bus_stops[j];
            
            double distance = harversine::distance_in_m(stop1.point, stop2.point);
            if (distance > max_distance) continue;

            string line_code = stop1.code + " - " + stop2.code;
            if (!has_line(line_code, Direction::NORMAL)) {
                add_line(line_code, Direction::NORMAL, "On foot - " + stop1.code + " - " + stop2.code);
                add_line_stop(line_code, Direction::NORMAL, stop1.code);
                add_line_stop(line_code, Direction::NORMAL, stop2.code);
            }

            if (!has_line(line_code, Direction::REVERSED)) {
                add_line(line_code, Direction::REVERSED, "On foot - " + stop1.code + " - " + stop2.code);
                add_line_stop(line_code, Direction::REVERSED, stop2.code);
                add_line_stop(line_code, Direction::REVERSED, stop1.code);
            }
        }
    }
}

list<Pathfinding::Node> Pathfinding::get_least_distance_path(string start, string end) {
    if (!has_bus_stop(start) || !has_bus_stop(end)) return {};

    LeastDistanceGraph graph(bus_stops.size());

    for (const Line &line : lines) {
        list<int> line_bus_stops = get_bus_stops(line.code, line.dir);
        
        auto current = line_bus_stops.begin();
        auto next = line_bus_stops.begin(); next++;

        while (current != line_bus_stops.end() && next != line_bus_stops.end()) {
            graph.add_edge(
                *current,
                *next,
                harversine::distance_in_m(
                    bus_stops.at(*current).point,
                    bus_stops.at(*next).point
                )
            );

            current++; next++;
        }
    }

    list<Pathfinding::Node> result;
    
    list<int> path = graph.get_path(bus_stop_positions.at(start), bus_stop_positions.at(end));

    auto current = path.begin();
    auto next = path.begin(); next++;

    while (current != path.end()) {
        BusStop &stop = bus_stops.at(*current);

        Pathfinding::Node node;
        node.stop = names::get_bus_stop_name(stop.code, stop.name);

        if (next != path.end()) {
            list<string> connecting_lines;

            auto it = stop.destinations.begin();
            while (it != stop.destinations.end()) {
                if ((*it).second == *next) {
                    int line_index = line_positions.at((*it).first);
                    Line &line = lines.at(line_index);
                    connecting_lines.push_back(names::get_line_name(line.name, line.dir));
                }

                it++;
            }

            node.lines = connecting_lines;
        }

        result.push_back(node);
        current++; next++;
    }
    
    return result;
}