// Project: OpenGameInput
// File: src/listener.cpp
// Description: An action event callback recipient.
// License: MIT
// https://github.com/colleen05/OpenGameInput

#include "oginput/listener.hpp"

void ogi::listener::set_callback(const std::string &action_name, callback callback_function) {
    _callbacks.insert_or_assign(action_name, callback_function);
}

void ogi::listener::clear_callback(const std::string &action_name) {
    if(_callbacks.find(action_name) != _callbacks.end()) return;
    _callbacks.erase(action_name);
}

std::optional<ogi::callback> ogi::listener::get_callback(const std::string &action_name) {
    auto it = _callbacks.find(action_name);
    if(it == _callbacks.end()) return {};

    return it->second;
}

void ogi::listener::invoke(const std::string &action_name, invocation_args values) {
    try {
        auto func = get_callback(action_name).value();

        if(std::holds_alternative<button_callback>(func)) {
            const button_activity ba = std::get<button_activity>(values);
            std::get<button_callback>(func)(ba);

        } else if(std::holds_alternative<scalar_callback>(func)) {
            const float s = std::get<float>(values);
            std::get<scalar_callback>(func)(s);
            
        } else if(std::holds_alternative<planar_callback>(func)) {
            const auto [s1, s2] = std::get<std::pair<float, float>>(values);
            std::get<planar_callback>(func)(s1, s2);
        }
    } catch(std::exception &e) { }
}

ogi::listener::listener() {}
ogi::listener::~listener() {}