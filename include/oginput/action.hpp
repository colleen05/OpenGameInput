// Project: OpenGameInput
// File: include/oginput/action.hpp
// Description: An input "idea" that can have multiple triggers.
// License: MIT
// https://github.com/colleen05/OpenGameInput

#ifndef OGI_ACTION_HPP
#define OGI_ACTION_HPP

#include "oginput/input.hpp"

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

namespace ogi {
    enum class button_activity {
        up          = 0,    //!< Up; not pressed, held, or released.
        pressed     = 1,    //!< Just been pressed.
        down        = 2,    //!< Been held more than 1 frame.
        released    = 3     //!< Just been released.
    };

    struct button_control {
        std::set<keyboard_event> keyboard_events;   //!< Which keyboard events are counted.
        std::set<mouse_event> mouse_events;         //!< Which mouse events are counted.
        std::set<gamepad_event> gamepad_events;     //!< Which gamepad events are counted.
    };

    struct scalar_control {
        std::map<keyboard_key, float> keyboard_keys;    //!< Each accounted keyboard key weight.
        std::map<mouse_input, float> mouse_inputs;      //!< Each accounted mouse input weight.
        std::map<gamepad_input, float> gamepad_inputs;  //!< Each accounted gamepad input weight.
    };

    struct planar_control {
        scalar_control x_control;  //!< Scalar control to determine the X component.
        scalar_control y_control;  //!< Scalar control to determine the Y component.
    };

    struct action {
        std::variant<
            std::vector<button_control>,
            std::vector<scalar_control>,
            std::vector<planar_control>
        > controls;
    };

    using action_map = std::unordered_map<std::string, action>;
}

#endif