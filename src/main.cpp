#include <SFML/Graphics.hpp>
#include <iostream>
#include "tiles.h"
#include "character.h"
#include "maps.cpp" // Currently creating my maps using cpp
#include "user_events.h"
#include "logger.h"


// Possible Optimization. Currently checks against every possible boundary.
bool has_collided(TileMap& map, sf::Sprite character){
    for (auto& o: map.obstacles) {
        auto a = o->getGlobalBounds();
        auto b = character.getGlobalBounds();
        if(a.intersects(b)) {
            return true;
        };
    }
    return false;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "test rpg");

    Character character;
    TileMap map = Maps::greenlands();
    character.setPosition(WIDTH/2,HEIGHT/2);
    Logger* logger = Logger::getInstance();

    bool show_logs = true;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0;
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::F1) show_logs = !show_logs;

        }
        auto e = get_user_event();

        if (!e.has_moved) character.stop_move();
        if (e.has_moved) { 
            // To simulate movement, the map moves while the character stays on the spot.
            character.move(e.x,e.y);
            map.move(-e.x,-e.y);
            if (has_collided(map, character)) map.move(e.x,e.y);
        }
        window.clear();
        

        window.draw(map);
        window.draw(character);


        logger->addDebug("x_offset: " + std::to_string(map.x) +"\ny_offset: "+ std::to_string(map.y));
        if(show_logs)window.draw(*logger);
        logger->clear();

        window.display();
    }

    return 0;
}