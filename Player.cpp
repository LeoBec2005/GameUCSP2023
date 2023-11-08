#include "Player.h"

Player::Player(float radius, float speed, int life) : Entity(radius, speed, life) {
    setHitbox(radius);
    shape.setFillColor(sf::Color::Blue);
}

void Player::update(sf::Time deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        shape.move(0, -speed * deltaTime.asSeconds());
        hitbox.move(0, -speed * deltaTime.asSeconds());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        shape.move(-speed * deltaTime.asSeconds(), 0);
        hitbox.move(-speed * deltaTime.asSeconds(), 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        shape.move(0, speed * deltaTime.asSeconds());
        hitbox.move(0, speed * deltaTime.asSeconds());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        shape.move(speed * deltaTime.asSeconds(), 0);
        hitbox.move(speed * deltaTime.asSeconds(), 0);
    }
}

void Player::Attack1(Entity* target) {
    if (target) {
        // Obtener la posición del jugador y del objetivo
        sf::Vector2f playerPosition = getPosition();
        sf::Vector2f targetPosition = target->getPosition();

        // Calcular la distancia entre el jugador y el objetivo
        float distance = std::sqrt((playerPosition.x - targetPosition.x) * (playerPosition.x - targetPosition.x) +
            (playerPosition.y - targetPosition.y) * (playerPosition.y - targetPosition.y));

        // Definir una distancia umbral de 10.0f
        float thresholdDistance = 10.0f;

        if (distance <= thresholdDistance) {
            target->setLife(target->getLife() - 10);
        }
    }
}

void Player::Death() {
    // Hacer que el jugador deje de moverse
    setSpeed(0.0f);
    // Establecer la vida en 0
    setLife(0);
    // Eliminar la forma y la hitbox
    shape.setFillColor(sf::Color::Transparent);
    // Restablecer la posición a un valor fuera de la pantalla o a un lugar seguro
    setPosition(-1000.0f, -1000.0f);
}