#include <iostream>

#include "config.h"
#include "dataset.h"

#include "graphs/least_stops.h"

using namespace std;

int main() {
    
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
