#include "character.h"

sf::IntRect run_texture(bool move_left, int frame) {
    int row = move_left ? 5 : 7;
    return sf::IntRect(frame * 120, row * 130, 120, 130);
}
sf::IntRect stop_texture = sf::IntRect(0, 0, 120, 130);


Character::Character() {
    texture.loadFromFile("./assets/link.png");
    this->setTexture(texture);
    stop_move();
}

void Character::move(float x, float y) {
    sf::Sprite::move(x,y);
    move_left = x < 0;
    this->setTextureRect(run_texture(move_left, i));
    i = (i + 1) % 10;

}
void Character::stop_move() {
    i = 0;
    this->setTextureRect(stop_texture);
}

