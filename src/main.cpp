#include <SFML/Graphics.hpp>
#include <iostream>
#include "tiles.h"
#include "character.h"
#include "maps.cpp" // Currently creating my maps using cpp
#include "user_events.h"

// Possible Optimization. Currently checks against every possible boundary.
bool has_collided(TileMap& map, sf::Sprite character){
    for (auto& o: map.obstacles) {
        auto a = o.getGlobalBounds();
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


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        auto e = get_user_event();

        if (!e.has_moved) character.stop_move();
        if (e.has_moved) { 
            character.move(e.x,e.y);
            if (has_collided(map, character)) character.move(-e.x,-e.y);
        }

        window.clear();

        window.draw(map);
        window.draw(character);
        window.display();
    }

    return 0;
}