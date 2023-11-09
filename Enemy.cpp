#include "enemy.h"

Enemy::Enemy(float radius, float speed, int life)
    : Entity(radius, speed, life), target(nullptr) {
    setHitbox(radius);
    shape.setFillColor(sf::Color::Red);
}

void Enemy::setTarget(Entity* target) {
    this->target = target;
}

void Enemy::update(sf::Time deltaTime) {
    // Obtener la posición actual del jugador
    sf::Vector2f targetPosition = target->getPosition();

    // Calcular la dirección hacia el jugador
    sf::Vector2f direction = targetPosition - getPosition();
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 0) {
        direction /= distance; // Normalizar la dirección

        // Mover el enemigo hacia el jugador
        shape.move(direction * speed * deltaTime.asSeconds());

        // Actualizar la posición de la hitbox
        hitbox.move(direction * speed * deltaTime.asSeconds());
    }
}

void Enemy::Attack1(Entity* target) {
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
                target->setLife(target->getLife() - 0.5);
        }
    }
}

void Enemy::Death() {
    // Hacer que el enemigo deje de moverse
    setSpeed(0.0f);
    // Establecer la vida en 0
    setLife(0);
    // Eliminar la forma y la hitbox
    shape.setFillColor(sf::Color::Transparent);
    // Restablecer la posición a un valor fuera de la pantalla o a un lugar seguro
    setPosition(-1000.0f, -1000.0f);
}
