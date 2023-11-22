#ifndef LEVEL_H
#define LEVEL_H


#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Settings.h"


class Level {
    public:
    Level() {

    }
	void level1() {
        sf::RenderWindow window(sf::VideoMode(Settings::Width, Settings::Height), "Juego SFML");

        Player* player = new Player(30, 200.0f, 200);
        player->setPosition(100, 100);
        Enemy* enemy = new Enemy(30, 200.0f, 50);
        enemy->setPosition(600, 400);
        enemy->setTarget(player);

        Settings healthBar(player->getLife());

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
                player->Death();
            }
            if (enemy->getLife() <= 0) {
                enemy->Death();
            }
            player->update(deltaTime);
            enemy->update(deltaTime);

            window.clear();
            player->draw(window); // Llama a la función draw de Player que ya incluye la llamada a window.draw()
            enemy->draw(window);  // Llama a la función draw de Enemy que ya incluye la llamada a window.draw()

            healthBar.draw(window);
            healthBar.update(player->getLife());

            window.display();
        }

        delete player;
        delete enemy;
	}
};

#endif