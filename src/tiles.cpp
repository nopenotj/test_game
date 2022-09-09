#include <SFML/Graphics.hpp>
#include "constants.h"
#include "tiles.h"
#include <iostream>
#include "logger.h"

Logger* logger = Logger::getInstance();


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

TileMap::TileMap() {}
void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    int r_start = -y/TILE_SIZE > 0 ? -y/TILE_SIZE : 0, r_end = (-y+HEIGHT)/ TILE_SIZE + 1 > ROW ? ROW : (-y+HEIGHT)/ TILE_SIZE + 1;
    int c_start = -x/TILE_SIZE > 0 ? -x/TILE_SIZE : 0, c_end = (-x + WIDTH)/TILE_SIZE + 1 > COLUMN ? COLUMN : (-x + WIDTH)/TILE_SIZE + 1;

    logger->addDebug("r_start: " +std::to_string(r_start) +"\nr_end: "+ std::to_string(r_end)); 
    for(int r=r_start; r < r_end; r++)
        for(int c=c_start; c < c_end; c++){
            sf::Transform translation;
            translation.translate(x + c * TILE_SIZE, y + r * TILE_SIZE);
            target.draw(tiles[r][c], translation);
    }
}

void TileMap::move(float x, float y) {
    this->x += x;
    this->y += y;
}

