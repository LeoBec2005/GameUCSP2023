#include <SFML/Graphics.hpp>
#include <cmath>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Juego SFML");

    Player* player = new Player(30, 200.0f, 100);
    player->setPosition(100, 100);

    Entity* enemy = new Enemy(30, 100.0f, 50, *static_cast<Player*>(player));
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
            player->Attack1(enemy); // Asignamos a Enemy como el objetivo de Player
        }

        if (player->getLife() <= 0) {
            player->Death(); // Hacer que el jugador desaparezca
        }

        if (enemy->getLife() <= 0) {
            enemy->Death(); // Hacer que el enemigo desaparezca
        }

        player->update(deltaTime);
        enemy->update(deltaTime);

        window.clear();
        player->draw(window);
        enemy->draw(window);
        window.display();
    }

    delete player;
    delete enemy;

    return 0;
}