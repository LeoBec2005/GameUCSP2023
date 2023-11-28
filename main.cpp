#include <SFML/Graphics.hpp>
#include <cmath>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Settings.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(Settings::Width, Settings::Height), "SFML UCSPGame");

    Player* player = new Player(200.0f, 100, 80.0f);
    player->setPosition(750, 400);

    Enemy* enemy = new Enemy(100.0f, 50, 20.0f);
    enemy->setPosition(600, 400);

    Settings healthBar(player->getLife());
    player->setTarget(enemy);
    enemy->setTarget(player);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        player->Attack1(enemy);
        enemy->Attack1(player);

        if (player->getLife() <= 0) {
            player->Death();
            enemy->Death();
        }

        if (enemy->getLife() <= 0) {
            enemy->Death();
            enemy->setTarget(player);
        }

        player->update(deltaTime);
        enemy->update(deltaTime);

        window.clear();
        player->draw(window);
        enemy->draw(window);

        healthBar.draw(window);
        healthBar.update(player->getLife());

        window.display();
    }

    delete player;
    delete enemy;

    return 0;
}