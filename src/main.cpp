#include <SFML/Graphics.hpp>
#include <iostream>
#include "tiles.h"
#include "character.h"
#include "maps.cpp" // Currently creating my maps using cpp


// Possible Optimization. Currently checks against every possible boundary.
bool has_collided(TileMap& map, sf::Sprite character){
    std::vector<Tile> obstacle;

    for(auto &i :map.tiles[0]) obstacle.push_back(i);
    obstacle.push_back(map.tiles[3][3]);
    
    for (auto& o: obstacle) {
        auto a = o.getGlobalBounds();
        auto b = character.getGlobalBounds();
        if(a.intersects(b)) {
            return true;
        };
    }
    return false;
}

struct UserEvent {
    float x,y;
    bool has_moved;
};

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

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "test rpg");

    Character character;
    TileMap map = Maps::greenlands();
    character.setScale(sf::Vector2f(0.5,0.5));
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
        for(auto& r: map.tiles)
            for(auto& c: r)
                window.draw(c);
        
        window.draw(character);
        window.display();
    }

    return 0;
}