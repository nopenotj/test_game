#include "logger.h"

Logger* Logger::singleton = nullptr; 
Logger::Logger() {
    font.loadFromFile("./assets/arial.ttf");
    text.setFont(font); // font is a sf::Font
    text.setCharacterSize(24); // in pixels, not points!
}

Logger* Logger::getInstance() {
    if (singleton == nullptr) {
        singleton = new Logger();
    } 
    return singleton;
}
void Logger::addDebug(std::string s) {
    text.setString(text.getString() + "\n"+ s);
}
void Logger::clear() {
    text.setString("");
}
void Logger::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(text);
}


