// Project: OpenGameInput
// File: include/oginput/input.hpp
// Description: Basic input definitions.
// License: MIT
// https://github.com/colleen05/OpenGameInput

#ifndef OGI_INPUT_HPP
#define OGI_INPUT_HPP

#include <variant>
#include <utility>

namespace ogi {
    using device_id = int;  //!< Numerical ID number of devices. -1 is used to denote an unspecified device.

    enum class device_type {
        unknown     = -1,   //!< Unknown HID device
        keyboard    = 0,    //!< Keyboards
        mouse       = 1,    //!< Mice
        gamepad     = 2     //!< Gamepads / "controllers"
    };

    enum class keyboard_key {
        unknown         = -1,   //!< Unknown key
        none            = 0,    //!< No key / NULL

        apostrophe      = 39,   //!< Key: '
        comma           = 44,   //!< Key: ,
        minus           = 45,   //!< Key: -
        period          = 46,   //!< Key: .
        slash           = 47,   //!< Key: /
        zero            = 48,   //!< Key: 0
        one             = 49,   //!< Key: 1
        two             = 50,   //!< Key: 2
        three           = 51,   //!< Key: 3
        four            = 52,   //!< Key: 4
        five            = 53,   //!< Key: 5
        six             = 54,   //!< Key: 6
        seven           = 55,   //!< Key: 7
        eight           = 56,   //!< Key: 8
        nine            = 57,   //!< Key: 9
        semicolon       = 59,   //!< Key: ;
        equal           = 61,   //!< Key: =
        a               = 65,   //!< Key: a
        b               = 66,   //!< Key: b
        c               = 67,   //!< Key: c
        d               = 68,   //!< Key: d
        e               = 69,   //!< Key: e
        f               = 70,   //!< Key: f
        g               = 71,   //!< Key: g
        h               = 72,   //!< Key: h
        i               = 73,   //!< Key: i
        j               = 74,   //!< Key: j
        k               = 75,   //!< Key: k
        l               = 76,   //!< Key: l
        m               = 77,   //!< Key: m
        n               = 78,   //!< Key: n
        o               = 79,   //!< Key: o
        p               = 80,   //!< Key: p
        q               = 81,   //!< Key: q
        r               = 82,   //!< Key: r
        s               = 83,   //!< Key: s
        t               = 84,   //!< Key: t
        u               = 85,   //!< Key: u
        v               = 86,   //!< Key: v
        w               = 87,   //!< Key: w
        x               = 88,   //!< Key: x
        y               = 89,   //!< Key: y
        z               = 90,   //!< Key: z
        left_bracket    = 91,   //!< Key: [
        backslash       = 92,   //!< Key: '\'
        right_bracket   = 93,   //!< Key: ]
        grave           = 96,   //!< Key: `

        space           = 32,   //!< Key: space
        escape          = 256,  //!< Key: esc
        enter           = 257,  //!< Key: enter
        tab             = 258,  //!< Key: tab
        backspace       = 259,  //!< Key: backspace
        insert          = 260,  //!< Key: ins
        del             = 261,  //!< Key: del
        right           = 262,  //!< Key: cursor right
        left            = 263,  //!< Key: cursor left
        down            = 264,  //!< Key: cursor down
        up              = 265,  //!< Key: cursor up
        page_up         = 266,  //!< Key: page up
        page_down       = 267,  //!< Key: page down
        home            = 268,  //!< Key: home
        end             = 269,  //!< Key: end
        caps_lock       = 280,  //!< Key: caps lock
        scroll_lock     = 281,  //!< Key: scroll down
        num_lock        = 282,  //!< Key: num lock
        print_screen    = 283,  //!< Key: print screen
        pause           = 284,  //!< Key: pause
        f1              = 290,  //!< Key: f1
        f2              = 291,  //!< Key: f2
        f3              = 292,  //!< Key: f3
        f4              = 293,  //!< Key: f4
        f5              = 294,  //!< Key: f5
        f6              = 295,  //!< Key: f6
        f7              = 296,  //!< Key: f7
        f8              = 297,  //!< Key: f8
        f9              = 298,  //!< Key: f9
        f10             = 299,  //!< Key: f10
        f11             = 300,  //!< Key: f11
        f12             = 301,  //!< Key: f12
        left_shift      = 340,  //!< Key: shift left
        left_control    = 341,  //!< Key: control left
        left_alt        = 342,  //!< Key: alt left
        left_super      = 343,  //!< Key: super left
        right_shift     = 344,  //!< Key: shift right
        right_control   = 345,  //!< Key: control right
        right_alt       = 346,  //!< Key: alt right
        right_super     = 347,  //!< Key: super right
        kb_menu         = 348,  //!< Key: kb menu

        keypad_0        = 320,  //!< Key: keypad 0
        keypad_1        = 321,  //!< Key: keypad 1
        keypad_2        = 322,  //!< Key: keypad 2
        keypad_3        = 323,  //!< Key: keypad 3
        keypad_4        = 324,  //!< Key: keypad 4
        keypad_5        = 325,  //!< Key: keypad 5
        keypad_6        = 326,  //!< Key: keypad 6
        keypad_7        = 327,  //!< Key: keypad 7
        keypad_8        = 328,  //!< Key: keypad 8
        keypad_9        = 329,  //!< Key: keypad 9
        keypad_decimal  = 330,  //!< Key: keypad .
        keypad_divide   = 331,  //!< Key: keypad /
        keypad_multiply = 332,  //!< Key: keypad *
        keypad_subtract = 333,  //!< Key: keypad -
        keypad_add      = 334,  //!< Key: keypad +
        keypad_enter    = 335,  //!< Key: keypad enter
        keypad_equal    = 336,  //!< Key: keypad =
    };

    enum class mouse_button {
        unknown = -1,   //!< Unknown mouse button
        left    = 0,    //!< Left button (MB1)
        right   = 1,    //!< Right button (MB2)
        middle  = 2,    //!< Middle button (MB3)
        side    = 3,    //!< Side button
        extra   = 4,    //!< Extra button
        forward = 5,    //!< Forward button
        back    = 6,    //!< Back button
    };

    enum class mouse_axis {
        unknown     = -1,   //!< Unknown mouse axis
        x           = 0,    //!< Positional X delta
        y           = 1,    //!< Positional Y delta
        scroll_v    = 2,    //!< Vertical scroll delta
        scroll_h    = 3     //!< Horizontal scroll delta
    };

    enum class gamepad_button {
        unknown             = -1,   //!< Unknown button

        left_face_up        = 0,    //!< Top button,   left side (D-Pad Up)
        left_face_right     = 1,    //!< Right button, left side (D-Pad Right)
        left_face_down      = 2,    //!< Down button,  left side (D-Pad down)
        left_face_left      = 3,    //!< Left button,  left side (D-Pad Left)

        right_face_up       = 4,    //!< Top button,   right side (PS3: Triangle / Xbox: Y)
        right_face_right    = 5,    //!< Right button, right side (PS3: Square   / Xbox: X)
        right_face_down     = 6,    //!< Down button,  right side (PS3: Cross    / Xbox: A)
        right_face_left     = 7,    //!< Left button,  right side (PS3: Circle   / Xbox: B)

        left_trigger1       = 8,    //!< Left bumper   (L1)
        left_trigger2       = 9,    //!< Left trigger  (L2)
        right_trigger1      = 10,   //!< Right bumper  (R1)
        right_trigger2      = 11,   //!< Right trigger (R2)

        middle_left         = 12,   //!< Leftmost centre button  (PS3: Select)
        middle              = 13,   //!< Middle centre button    (PS3: PS / Xbox: XBOX)
        middle_right        = 14,   //!< Rightmost centre button (PS3: Start)

        left_thumb          = 15,   //!< Left thumbstick button
        right_thumb         = 16,   //!< Right thumbstick button
    };

    enum class gamepad_axis {
        unknown         = -1,   //!< Unknown gamepad axis
        left_x          = 0,    //!< Left thumbstick X position
        left_y          = 1,    //!< Left thumbstick Y position
        right_x         = 2,    //!< Right thumbstick X position
        right_y         = 3,    //!< Right thumbstick Y position
        left_trigger    = 4,    //!< Left trigger depression
        right_trigger   = 5     //!< Right trigger depression
    };

    using mouse_input = std::variant<mouse_button, mouse_axis>;
    using gamepad_input = std::pair<device_id, std::variant<gamepad_button, gamepad_axis>>;
}

#endif