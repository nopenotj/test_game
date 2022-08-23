
#include "tiles.h"

namespace Maps {
    TileMap greenlands() {
        TileMap map;
        for(auto& r: map.tiles) 
            for(auto& c: r) {
                c.setTextureRect(Tiles::Grass);
            }    
        for(auto& c: map.tiles[0]) c.setTextureRect(Tiles::Wood);
        map.tiles[3][3].setTextureRect(Tiles::Stone);
        return map;
    }
}