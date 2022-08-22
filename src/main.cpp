#include <SFML/Graphics.hpp>
#include <iostream>

#define LEN(arr) sizeof(arr)/sizeof(arr[0])

class Character : public sf::Sprite {
private:
    sf::Texture texture;
    bool move_left;
    int i = 0;
public:
    Character() {
        texture.loadFromFile("./assets/link.png");
        this->setTexture(texture);
        stop_move();
    }

    void move(float x, float y) {
        sf::Sprite::move(x,y);
        move_left = x < 0;
        int row = move_left ? 5 : 7;
        this->setTextureRect(sf::IntRect(i * 120, row * 130, 120, 130));
        i = (i + 1) % 10;

    }
    void stop_move() {
        i = 0;
        this->setTextureRect(sf::IntRect(0, 0, 120, 130));
    }

};

const constexpr float TILE_SIZE = 50;
const constexpr int HEIGHT = 600, WIDTH = 800;

struct Tile : sf::RectangleShape{
    Tile() : RectangleShape(sf::Vector2f(TILE_SIZE, TILE_SIZE)){
        // this->setFillColor(sf::Color::Green);
        // this->setOutlineThickness(1.f);
    }
};

struct TileMap {
    Tile tiles[(int)(HEIGHT/TILE_SIZE)][(int)(WIDTH/TILE_SIZE)];
    TileMap() {
        setPosition();
    }
    void setPosition() {
        for(int r=0; r < LEN(tiles); r++)
            for(int c=0; c < LEN(tiles[r]); c++)
                tiles[r][c].setPosition(c * TILE_SIZE,r * TILE_SIZE);
    }
};

//TODO : Add in texture
void load_map(TileMap& map) {
    static sf::Texture texture;
    texture.loadFromFile("./assets/textures.png");

    int TEXTURE_SIZE = 15;
    for(auto& r: map.tiles) 
        for(auto& c: r) {
            c.setTexture(&texture); // texture is a sf::Texture
            c.setTextureRect(sf::IntRect(0 * TEXTURE_SIZE, 28 * TEXTURE_SIZE - 2, TEXTURE_SIZE, TEXTURE_SIZE));
        } 
        
    for(auto& c: map.tiles[0]) c.setFillColor(sf::Color::Blue);
    map.tiles[3][3].setTextureRect(sf::IntRect(0 * TEXTURE_SIZE, 495, TEXTURE_SIZE, TEXTURE_SIZE));
}
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

UserEvent handle_input() {
    float d = 0.5;
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
    TileMap map;

    character.setPosition(500,500);
    load_map(map);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        auto e = handle_input();

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