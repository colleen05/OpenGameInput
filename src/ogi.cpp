// Project: OpenGameInput
// File: src/ogi.cpp
// Description: OpenGameInput source file.
// License: MIT
// https://github.com/colleen05/OpenGameInput

#include "oginput/ogi.hpp"

#include <iostream>

void ogi::print_lib_info() {
    std::cout
        << "Using " OGI_RELEASE " " OGI_COPYRIGHT "." << std::endl
        << "Distributed under the " OGI_LICENSE " license." << std::endl
        << std::endl
        << "See " OGI_INFO_LINK " for more details." << std::endl;
        
    return;
}