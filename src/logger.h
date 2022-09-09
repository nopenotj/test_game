#pragma once
#include <SFML/Graphics.hpp>
class Logger : public sf::Drawable {
    static Logger* singleton;
    sf::Text text;
    sf::Font font;
    Logger();
public:
    static Logger* getInstance();
    void addDebug(std::string);
    void clear();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};