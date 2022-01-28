#pragma once

#include "interact.h"
#include "pathfinding.h"

#include <vector>
#include <string>

class UI {
    Pathfinding pathfinding;
    Pathfinding current_pathfinding;
    std::string start_stop;
    std::string end_stop;
    double distance;
    bool is_night;

    std::pair<double, double> ask_coordinates();
    std::string ask_stop();
    double ask_distance_on_foot();

    void show_trip(const std::list<Pathfinding::Node> &nodes) const;

    Menu get_starting_point_menu();
    Menu get_ending_point_menu();
    Menu get_toggle_walking_menu();
    Menu get_night_line_menu();
    Menu get_trip_type_menu();

    public:
        UI(Pathfinding &pathfinding);

        void start();
};