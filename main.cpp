#include <iostream>

#include <string>
#include <sstream>
#include <utility>
#include "config.h"
#include "dataset.h"
#include "interact.h"
#include "names.h"
#include "pathfinding.h"

using namespace std;


// pair<double, double> askCoordinates() {
//     string point = read_value<GetLine>("Coordinates: ", "Please insert a valid point in the format 'x y'");

//     stringstream ss(point);
//     double x, y;

//     if (!(ss >> x >> y))
//         throw validation_error("The format of the point is incorrect");

//     return make_pair(x, y);
// }


// string askStops(const vector<string> &stops) {
//     string stop = read_value<string>("Stop name: ", "Please insert a valid stop", [&stops](const string &stop){
//         string stopUpper = transform(stop.begin(), stop.end(), stop.begin(), to);
//         if (!find(stops.begin(), stops.end(), stopUpper))
//             throw validation_error("The stop you entered doesn't exist");
//         return true;
//     });
    
//     return std::transform(stop.begin(), stop.end(), stop.begin(), ::toupper);
// }


// bool askOnFoot() {
//     char onFoot = read_value<char>("Willing to walk? ", "Please insert a valid answer ('Y'/'N')", [](const char &c) { return toupper(c) == 'N' || toupper(c) == 'Y'; });
//     return &onFoot == "Y";
// }

// bool allowBusChange() {
//     char allowBusChange = read_value<char>("Allow app to calculate route with bug changes?", "Please input a valid answer ('Y'/'N')", [](const char &c) { return toupper(c) == 'N' || toupper(c) == 'Y'; });
//     return &allowBusChange == "Y";
// }



// MenuBlock read_stop() {
//     MenuBlock starting_point_block;
//     starting_point_block.add_option("Coordinates", [](){

//     });
//     starting_point_block.add_option("Stop Name", [](){});

// }

int main() {

    Pathfinding path;

    for (const auto &stop : dataset::read_stops())
        path.add_bus_stop(stop.code, stop.name, stop.zone, stop.point);

    for (const auto &line : dataset::read_lines()) {
        path.add_line(line.code, line.dir, line.name);

        for (const auto &stop : line.stops)
            path.add_line_stop(line.code, line.dir, stop);
    }

    path.add_on_foot_segments(2000);

    for (const auto node : path.get_least_distance_path("MATM1", "CMP5")) {
        cout << "STOP: " << node.stop << endl;
        for (const auto line : node.lines.value_or<list<string>>({})) {
            cout << "LINE: " << line << endl;
        }

        cout << endl;
    }

    // auto stops = dataset::read_st>ops();
    // auto lines = dataset::read_lines();

    // try {
    //     Menu menu("Please select the starting point!");


    //     bool is_running = true;
    //     MenuBlock exit_block;
    //     exit_block.add_option("Exit", [&is_running]() { is_running = false; });

    //     menu.add_block(starting_point_block);



    // } catch (end_of_file_exception exception) {}


    // for (const auto &stop : dataset::read_stops()) {
    //     cout << "CODE: " << stop.code << '\n'
    //         << "NAME: " << stop.name << '\n'
    //         << "ZONE: " << stop.zone << '\n'
    //         << "POINT: (" << stop.point.first << ", " << stop.point.second << ')' << '\n'
    //         << endl;
    // }

    // cin.ignore(1);

    // for (const auto &line : dataset::read_lines()) {
    //     cout << "CODE: " << line.code << '\n'
    //         << "NAME: " << line.name << '\n'
    //         << "DIRECTION: " << line.dir << '\n'
    //         << "STOPS: " << '\n';

    //     for (const auto &stop : line.stops) {
    //         cout << '\t' << stop << '\n';
    //     }

    //     cout << '\n' << endl;
    // }

    return 0;
}
