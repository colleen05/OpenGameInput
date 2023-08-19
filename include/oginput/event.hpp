// Project: OpenGameInput
// File: include/oginput/event.hpp
// Description: Events - Bridgings between input fields and actual values / states.
// License: MIT
// https://github.com/colleen05/OpenGameInput

#ifndef OGI_EVENT_HPP
#define OGI_EVENT_HPP

#include "oginput/input.hpp"

#include <chrono>

namespace ogi {
    template<typename TField, typename TState>
    struct event {
        TField which;
        TState state;
        // std::chrono::time_point when;
    }; //!< Event template

    template<typename TButton>
    using button_event = event<TButton, bool>; //!< Generic button event template

    template<typename TAxis>
    using axis_event = event<TAxis, float>; //!< Generic axis event template

    using keyboard_event = button_event<keyboard_key>;          //!< Keyboard keys
    using mouse_button_event = button_event<mouse_button>;      //!< Mouse buttons (clicks, etc..)
    using mouse_axis_event = axis_event<mouse_axis>;            //!< Mouse axes (movement, scroll)
    using gamepad_button_event = button_event<gamepad_button>;  //!< Gamepad buttons
    using gamepad_axis_event = axis_event<gamepad_axis>;        //!< Gamepad axes (thumbsticks, triggers, etc..)

    using mouse_event = std::variant<mouse_button_event, mouse_axis_event>;         //!< Any mouse input
    using gamepad_event = std::variant<gamepad_button_event, gamepad_axis_event>;   //!< Any gamepad input
}

#endif