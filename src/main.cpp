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
        texture.loadFromFile("./assests/link.png");
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

struct Tile : sf::RectangleShape{
    Tile() : RectangleShape(sf::Vector2f(100.f, 100.f)){
        this->setFillColor(sf::Color::Green);
        // this->setOutlineColor(sf::Color::Magenta);
        this->setOutlineThickness(1.f);
    }
};

struct TileMap {
    Tile tiles[6][8];
    TileMap() {
        setPosition();
    }
    void setPosition() {
        for(int r=0; r < LEN(tiles); r++)
            for(int c=0; c < LEN(tiles[r]); c++)
                tiles[r][c].setPosition(c * 100,r * 100);
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "piggy rpg");

    Character character;
    TileMap map;

    for(auto& c: map.tiles[0]) c.setFillColor(sf::Color::Blue);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        float d = 0.5;

        float x,y = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  x -= d;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) x += d;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  y += d;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    x -= d;
        
        bool has_moved = x != 0 || y != 0;

        if (!has_moved) character.stop_move();

        if (has_moved) { // possible optimization
            // Check collision
            bool has_collided = false;
            auto& obstacle = map.tiles[0];
            for (auto& o: obstacle) {
                auto a = o.getGlobalBounds();
                auto b = character.getGlobalBounds();
                if(a.intersects(b)) {
                    has_collided = true;
                };
            }
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