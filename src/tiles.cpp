#include <SFML/Graphics.hpp>
#include "constants.h"
#include "tiles.h"
#include <iostream>

sf::Texture* get_texture() {
    static sf::Texture texture;
    static bool init;
    if (!init) {
        init = true;
        texture.loadFromFile("./assets/textures.png");
    }
    return &texture;
}

Tile::Tile() : RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE)){ 
    this->setTexture(get_texture()); // texture is a sf::Texture
}

TileMap::TileMap() {
    setPosition();
}

void TileMap::setPosition() {
    for(int r=0; r < LEN(tiles); r++)
        for(int c=0; c < LEN(tiles[r]); c++)
            tiles[r][c].setPosition(c * TILE_SIZE,r * TILE_SIZE);
}

int Tiles::TEXTURE_SIZE = 15;
