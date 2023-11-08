#include "Enemy.h"

Enemy::Enemy(float radius, float speed, int life, Player& player) : Entity(radius, speed, life), player(player) {
    setHitbox(radius);
    shape.setFillColor(sf::Color::Red);
}

void Enemy::update(sf::Time deltaTime) {
    // Obtener la posición actual del jugador
    sf::Vector2f playerPosition = player.getPosition();

    // Calcular la dirección hacia el jugador
    sf::Vector2f direction = playerPosition - getPosition();
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 0) {
        direction /= distance; // Normalizar la dirección

        // Mover el enemigo hacia el jugador
        shape.move(direction * speed * deltaTime.asSeconds());

        // Actualizar la posición de la hitbox
        hitbox.move(direction * speed * deltaTime.asSeconds());
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
