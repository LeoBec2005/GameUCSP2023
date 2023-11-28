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
    sf::Vector2f targetPosition = target->getPosition();

    sf::Vector2f direction = targetPosition - getPosition();
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 0) {
        direction /= distance;

        shape.move(direction * speed * deltaTime.asSeconds());

        hitbox.move(direction * speed * deltaTime.asSeconds());
    }
}

void Enemy::Attack1(Entity* target) {
    if (target) {
        sf::Vector2f playerPosition = getPosition();
        sf::Vector2f targetPosition = target->getPosition();

        float distance = std::sqrt((playerPosition.x - targetPosition.x) * (playerPosition.x - targetPosition.x) +
            (playerPosition.y - targetPosition.y) * (playerPosition.y - targetPosition.y));

        float thresholdDistance = 10.0f;

        if (distance <= thresholdDistance) {
                target->setLife(target->getLife() - 0.5);
        }
    }
}

void Enemy::Death() {
    setSpeed(0.0f);
    setLife(0);
    shape.setFillColor(sf::Color::Transparent);
    setPosition(-1000.0f, -1000.0f);
}
