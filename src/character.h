#include <SFML/Graphics.hpp>

class Character : public sf::Sprite {
private:
    sf::Texture texture;
    bool move_left;
    int i = 0;
public:
    Character();
    void move(float x, float y);
    void stop_move();
};