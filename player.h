#ifndef player_h
#define player_h
#pragma once
using namespace std;

class Player { 
private:
    sf::CircleShape circle;
    sf::Texture walktexture;
    sf::Sprite playerSprite;
    float xtexture = 0;
    sf::Clock animationClock;
    float animationSpeed = 0.2;
    float x = 400;
    float y = 300;
    float speed = 0.5;

public:
Player() {
    circle.setRadius(50);
    circle.setPosition(x, y);
    circle.setFillColor(sf::Color::Blue);
    walktexture.loadFromFile("assets/walksprites.png");
    playerSprite.setTexture(walktexture);
    playerSprite.setScale(6,6);
    playerSprite.setTextureRect(sf::IntRect(0, 0, 25.25, 32.25));
	}

void move(int width, int height) {
    // Detectar las teclas presionadas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        y -= speed;
        if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
            xtexture += 25.5;
            if (xtexture >= 101)
                xtexture = 0;
            playerSprite.setTextureRect(sf::IntRect(xtexture, 96.75, 22, 32.25));
            animationClock.restart();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        x -= speed;
        if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
            xtexture += 25.5;
            if (xtexture >= 101)
                xtexture = 0;
            playerSprite.setTextureRect(sf::IntRect(xtexture, 32.25, 20, 32.25));
            animationClock.restart();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        y += speed;
        if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
            xtexture += 25.5;
            if (xtexture >= 101)
                xtexture = 0;
            playerSprite.setTextureRect(sf::IntRect(xtexture, 0, 22, 32.25));
            animationClock.restart();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        x += speed;
        if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
            xtexture += 25.5;
            if (xtexture >= 101)
                xtexture = 0;
            playerSprite.setTextureRect(sf::IntRect(xtexture, 64.5, 20, 32.25));
            animationClock.restart();
        }
    }
    playerSprite.setPosition(x, y);
    circle.setPosition(x, y);

    std::cout << std::fixed << std::setprecision(1);
    cout << "x:" << x << "     " << "y: " << y << endl;
    std::cout << std::defaultfloat;
    if (x == width-125) {
        x--;
    }
    if (x == 0) {
        x++;
    }
    if (y == 0) {
        y++;
    }
    if (y == height-200) {
        y--;
    }
}
void draw(sf::RenderWindow& window) {
    window.draw(playerSprite);
	}
};
#endif 