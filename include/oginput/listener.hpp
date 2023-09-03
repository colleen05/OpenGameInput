// Project: OpenGameInput
// File: include/oginput/listener.hpp
// Description: An action event callback recipient.
// License: MIT
// https://github.com/colleen05/OpenGameInput

#ifndef OGI_LISTENER_HPP
#define OGI_LISTENER_HPP

#include "oginput/event.hpp"
#include "oginput/action.hpp"

#include <unordered_map>
#include <functional>
#include <string>
#include <optional>
#include <utility>

namespace ogi {
    using button_callback = std::function<void(button_activity)>;
    using scalar_callback = std::function<void(float)>;
    using planar_callback = std::function<void(float, float)>;

    using callback = std::variant<button_callback, scalar_callback, planar_callback>;

    class listener {
        private:
            std::unordered_map<std::string, callback> _callbacks;
            
        public:
            void set_callback(const std::string &action_name, callback callback_function);
            void clear_callback(const std::string &action_name);
            std::optional<callback> get_callback(const std::string &action_name);
            
            using invocation_args = std::variant<button_activity, float, std::pair<float, float>>;
            void invoke(const std::string &action_name, invocation_args values);

            listener(std::unordered_map<std::string, callback> callbacks);
            listener();
            ~listener();
    };
}

#endif