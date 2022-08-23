#include <SFML/Graphics.hpp>
#include "constants.h"
#include "tiles.h"

TileMap::TileMap() {
    setPosition();
}

void TileMap::setPosition() {
    for(int r=0; r < LEN(tiles); r++)
        for(int c=0; c < LEN(tiles[r]); c++)
            tiles[r][c].setPosition(c * TILE_SIZE,r * TILE_SIZE);
}

int Tiles::TEXTURE_SIZE = 15;