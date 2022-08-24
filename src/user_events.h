#pragma once
#include <SFML/Graphics.hpp>

struct UserEvent {
    float x,y;
    bool has_moved;
};

UserEvent get_user_event();