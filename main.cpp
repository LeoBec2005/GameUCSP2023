#include <SFML/Graphics.hpp>
#include <cmath>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Settings.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(Settings::Width, Settings::Height), "Juego SFML");

    Player* player = new Player(30, 200.0f, 200);
    player->setPosition(100, 100);

    Enemy* enemy = new Enemy(30, 100.0f, 50);
    enemy->setPosition(600, 400);
    enemy->setTarget(player);

    Settings healthBar(player->getLife());
    //Settings healthBar(enemy->getLife());

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        player->Attack1(enemy);
        enemy->Attack1(player);

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

        // Dibuja la barra de vida después de los elementos del juego
        healthBar.draw(window);
        healthBar.update(player->getLife());

        window.display();
    }

    delete player;
    delete enemy;

    return 0;
}
