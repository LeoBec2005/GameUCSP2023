#ifndef player_h
#define player_h
#pragma once
using namespace std;

class Player { 
private:
    sf::CircleShape circle;
    float x = 400;
    float y = 300;
    float speed = 0.5;
public:
Player() {
    circle.setRadius(50);
    circle.setPosition(x, y);
    circle.setFillColor(sf::Color::Blue);
	}

void move(int width, int height) {
    // Detectar las teclas presionadas
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        y -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        y += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        x += speed;
    }
    std::cout << std::fixed << std::setprecision(1);
    cout << "x:" << x << "     " << "y: " << y << endl;
    std::cout << std::defaultfloat;
    if (x == width-100) {
        x--;
    }
    if (x == 0) {
        x++;
    }
    if (y == 0) {
        y++;
    }
    if (y == height-100) {
        y--;
    }
    circle.setPosition(x, y);
}
void draw(sf::RenderWindow& window) {
    window.draw(circle);
	}
};
#endif 