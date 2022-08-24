
#include "tiles.h"

namespace Maps {
    TileMap greenlands() {

        // Texturing Tiles
        TileMap map;
        for(auto& r: map.tiles) 
            for(auto& c: r) {
                c.setTextureRect(Tiles::Grass);
            }    
        for(auto& c: map.tiles[0]) c.setTextureRect(Tiles::Wood);
        map.tiles[3][3].setTextureRect(Tiles::Stone);

        // Adding Obstacles
        for(auto &i :map.tiles[0]) map.obstacles.push_back(i);
        map.obstacles.push_back(map.tiles[3][3]);

        return map;
    }
}