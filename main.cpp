
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(1720, 1080), "SFML Example");

    // Crear un círculo
    sf::CircleShape circle(50); // Radio del círculo
    circle.setFillColor(sf::Color::Blue); // Configurar el color del círculo
    int x = 400;
    int y = 300;
    double speed = 1;

    while (window.isOpen()) {

        circle.setPosition(x, y);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Detectar las teclas presionadas
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            y--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            x--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            y++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            x += speed;
        }
        cout << "x:" << x << " " << "y: " << y << endl;
        if (x == 1620) {
            x--;
        }
        if (x == 0) {
            x++;
        }
        if (y == 0) {
            y++;
        }
        if (y == 950) {
            y--;
        }

        // Dibujar el círculo en la ventana
        window.clear();
        window.draw(circle);
        window.display();
    }
    return 0;
}