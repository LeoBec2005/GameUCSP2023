#include <SFML/Graphics.hpp>
#include <cmath>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Juego SFML");

    // Crear un objeto Player con el nuevo constructor
    Player* player = new Player(30, 200.0f, 100, window);
    player->setPosition(100, 100);

    Entity* enemy = new Enemy(30, 100.0f, 50, *player); // Pasamos player como referencia
    enemy->setPosition(600, 400);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            player->Attack1(enemy);
        }

        player->update(deltaTime);
        enemy->update(deltaTime);

        player->CameraMovement();

        window.clear();
        player->draw(window);
        enemy->draw(window);
        window.display();
    }

    delete player;
    delete enemy;

    return 0;
}