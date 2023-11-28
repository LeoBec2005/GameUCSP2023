#include "Background.h"

Background::Background() {
    backgroundTexture.loadFromFile("assets//map3.jpg");
	backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(2.8, 2.3);
}


void Background::draw(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
}
