#pragma once

#include <string>
#include <vector>
#include <list>
#include <map>
#include <utility>

#include "config.h"
#include "direction.h"


namespace dataset {

    struct Line {
        std::string code;
        Direction dir;

        std::string name = "unknown";
        std::list<std::string> stops;
    };

    struct Stop {
        std::string code;

        std::string name = "unknown";
        std::string zone;
        std::pair<double, double> point;
    };

    /**
     * @brief
     *
     * @param names
     * @param line 
     * @param dir The line's direction
     * @return vector<string>
     */
    Line read_line(std::map<std::string, std::string> names, std::string line, Direction dir);

    std::vector<Stop> read_stops();

    std::vector<Line> read_lines();
}