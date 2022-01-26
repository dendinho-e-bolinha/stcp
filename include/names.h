#pragma once

#include <string>
#include "direction.h"

namespace names {

    std::string get_line_name(std::string name, Direction dir);
    std::string get_bus_stop_name(std::string code, std::string name);
}