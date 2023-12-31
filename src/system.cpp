// Project: OpenGameInput
// File: src/system.cpp
// Description: Central input system.
// License: MIT
// https://github.com/colleen05/OpenGameInput

#include "oginput/system.hpp"

void ogi::system::_clean_dead_listeners() {
    for(size_t i = 0; i < _actionListeners.size(); i++) {
        auto &l = _actionListeners[i];

        if(l.use_count() < 2)
            _actionListenerGarbage.push_back(i);
    }

    for(auto i : _actionListenerGarbage) {
        _actionListeners.erase(_actionListeners.begin() + i);
    }

    _actionListenerGarbage.clear();
}

void ogi::system::register_event(keyboard_event event) {
    _keyboardKeyStates.insert_or_assign(event.which, event.state);
}

void ogi::system::register_event(mouse_event event) {
    try {
        if(std::holds_alternative<mouse_button_event>(event)) {
            auto e = std::get<mouse_button_event>(event);
            _mouseButtonStates.insert_or_assign(e.which, e.state);

        }else if(std::holds_alternative<mouse_axis_event>(event)) {
            auto e = std::get<mouse_axis_event>(event);
            _mouseAxisStates.insert_or_assign(e.which, e.state);
        }
    } catch(std::exception &e) { }
}

void ogi::system::register_event(device_id id, gamepad_event event) {
    try {
        if(std::holds_alternative<gamepad_button_event>(event)) {
            if(_gamepadButtonStates.find(id) == _gamepadButtonStates.end())
                _gamepadButtonStates.insert(id, {}); 

            auto e = std::get<gamepad_button_event>(event);
            _gamepadButtonStates[id].insert_or_assign(e.which, e.state);

        }else if(std::holds_alternative<gamepad_axis_event>(event)) {
            if(_gamepadAxisStates.find(id) == _gamepadAxisStates.end())
                _gamepadAxisStates.insert(id, {});

            auto e = std::get<gamepad_axis_event>(event);
            _gamepadAxisStates[id].insert_or_assign(e.which, e.state);
        }
    } catch(std::exception &e) { }
}

void ogi::system::update() {
    // Clean up dead listeners.
    _clean_dead_listeners();

    // Move current state maps back
    _lastKeyboardKeyStates = std::move(_keyboardKeyStates);
    _lastMouseButtonStates = std::move(_mouseButtonStates);
    _lastGamepadButtonStates = std::move(_lastGamepadButtonStates);
}

void ogi::system::push_listener(std::shared_ptr<listener> listener) {
    _actionListeners.push_back(listener);
}

ogi::system::system() {}

ogi::system::~system() {
    _clean_dead_listeners();
}