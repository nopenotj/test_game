#include "user_events.h"

UserEvent get_user_event() {
    float d = 0.3;
    float x = 0,y = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  x -= d;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) x += d;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  y += d;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    y -= d;
    
    bool has_moved = x != 0 || y != 0;

    return {x,y,has_moved};
}