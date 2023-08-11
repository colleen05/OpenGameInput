// Project: OpenGameInput
// File: include/oginput/ogi.hpp
// Description: OpenGameInput header file.
// License: MIT
// https://github.com/colleen05/OpenGameInput

#ifndef OGI_HPP
#define OGI_HPP

#define OGI_VERSION_MAJOR      "0"
#define OGI_VERSION_MINOR      "0"
#define OGI_VERSION_RELEASE    "1"

#define OGI_VERSION "OpenGameInput " OGI_VERSION_MAJOR "." OGI_VERSION_MINOR
#define OGI_RELEASE OGI_VERSION "." OGI_VERSION_RELEASE

#define OGI_COPYRIGHT "Copyright (c) 2023 Colleen (\"colleen05\")"
#define OGI_LICENSE "MIT"

#define OGI_INFO_LINK "https://github.com/colleen05/OpenGameInput"

namespace ogi {
    void print_lib_info();
}

#endif