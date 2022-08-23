#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"

struct Tile : sf::RectangleShape{
    Tile();
};

struct TileMap {
    TileMap();
    Tile tiles[(int)(HEIGHT/TILE_SIZE)][(int)(WIDTH/TILE_SIZE)];
    void setPosition();
};

namespace Tiles {
    extern int TEXTURE_SIZE;

    const sf::IntRect Grass = sf::IntRect(0 * TEXTURE_SIZE, 28 * TEXTURE_SIZE - 3, TEXTURE_SIZE, TEXTURE_SIZE);
    const sf::IntRect Wood = sf::IntRect(0 , 96, TEXTURE_SIZE, TEXTURE_SIZE);
    const sf::IntRect Stone = sf::IntRect(0 * TEXTURE_SIZE, 495, TEXTURE_SIZE + 2, TEXTURE_SIZE + 2);
}