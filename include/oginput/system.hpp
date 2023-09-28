// Project: OpenGameInput
// File: include/oginput/system.hpp
// Description: Central input system.
// License: MIT
// https://github.com/colleen05/OpenGameInput

#ifndef OGI_SYSTEM_HPP
#define OGI_SYSTEM_HPP

#include "oginput/event.hpp"
#include "oginput/action.hpp"
#include "oginput/listener.hpp"

#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <memory>

#include <iostream>

namespace ogi {
    class system {
        private:
            std::map<keyboard_key, bool> _lastKeyboardKeyStates;
            std::map<mouse_button, bool> _lastMouseButtonStates;
            std::map<device_id, std::map<gamepad_button, bool>>
                _lastGamepadButtonStates;

            std::map<keyboard_key, bool> _keyboardKeyStates;
            std::map<mouse_button, bool> _mouseButtonStates;
            std::map<device_id, std::map<gamepad_button, bool>>
                _gamepadButtonStates;

            std::map<mouse_axis, float> _mouseAxisStates;

            std::map<device_id, std::map<gamepad_axis, float>> _gamepadAxisStates;

            std::vector<std::shared_ptr<listener>> _actionListeners;
            std::vector<size_t> _actionListenerGarbage;

            void _clean_dead_listeners();

        public:
            action_map actions;

            void register_event(keyboard_event event);
            void register_event(mouse_event event);
            void register_event(device_id id, gamepad_event event);

            void push_listener(std::shared_ptr<listener> listener);

            void update();

            system();
            ~system();
    };
}

#endif