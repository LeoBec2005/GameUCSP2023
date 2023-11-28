#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Settings.h"
#include "Background.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(Settings::Width, Settings::Height), "SFML UCSPGame");
    Background background;

    Player* player = new Player(200.0f, 10000, 80.0f);
    player->setPosition(750, 400);

    Enemy* enemy = new Enemy(100.0f, 50, 20.0f);
    enemy->setPosition(600, 400);

    Settings healthBar(player->getLife());
    player->setTarget(enemy);
    enemy->setTarget(player);

    sf::Clock clock;

    // Inicializar la semilla para números aleatorios
    std::srand(std::time(0));

    int score = 0; // Nueva variable para el puntaje

    sf::Font font;
    font.loadFromFile("assets//AldotheApache.ttf"); // Reemplaza con la ruta a tu archivo de fuente

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setPosition(10, 10); // Posición en la ventana
    scoreText.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Verifica si la tecla 'r' ha sido presionada
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                // Reinicia el juego
                delete player;
                delete enemy;

                player = new Player(200.0f, 10000, 80.0f);
                player->setPosition(750, 400);

                enemy = new Enemy(100.0f, 50, 20.0f);
                enemy->setPosition(600, 400);

                player->setTarget(enemy);
                enemy->setTarget(player);

                score = 0; // Reinicia el puntaje

                std::cout << "Juego reiniciado." << std::endl;
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
            score += 100; // Aumenta el puntaje en 100

            // Crear un nuevo enemigo aleatorio con posición aleatoria
            float speed = static_cast<float>(std::rand() % 450 + 200); // Velocidad entre 50 y 150
            int vida = std::rand() % 50 + 50; // Vida entre 50 y 100
            float damage = static_cast<float>(std::rand() % 30 + 10); // Daño entre 10 y 40

            float randomX = static_cast<float>(std::rand() % (Settings::Width - 50)); // Posición X aleatoria
            float randomY = static_cast<float>(std::rand() % (Settings::Height - 50)); // Posición Y aleatoria

            delete enemy; // Eliminar el enemigo existente

            enemy = new Enemy(speed, vida, damage);
            enemy->setPosition(randomX, randomY);
            enemy->setTarget(player);

            // Mostrar el puntaje actualizado en la consola (puedes cambiar esto según tus necesidades)
            std::cout << "Puntaje: " << score << std::endl;
        }

        player->update(deltaTime);
        enemy->update(deltaTime);

        // Dentro del bucle principal, actualiza el texto del puntaje
        scoreText.setString("Puntaje: " + std::to_string(score));

        window.clear();
        background.draw(window);
        player->draw(window);
        enemy->draw(window);

        healthBar.draw(window);
        healthBar.update(player->getLife());

        // Dibuja el texto del puntaje
        window.draw(scoreText);

        window.display();
    }

    delete player;
    delete enemy;

    return 0;
}
