#include "entity.h"

Entity::Entity(float speed, int life, float damage)
    : speed(speed), life(life), damage(damage) {
 
}

void Entity::draw(sf::RenderWindow& window) {
    window.draw(hitbox);
    window.draw(sprite);
}

void Entity::setPosition(float x, float y) {
    sprite.setPosition(x, y);
    hitbox.setPosition(x, y);
}

sf::Vector2f Entity::getPosition() const {
    return sprite.getPosition();
}

void Entity::setLife(int lifeValue) {
    life = lifeValue;
}

void Entity::setDamage(int damageValue) {
    damage = damageValue;
}

int Entity::getLife() const {
    return life;
}

void Entity::setSpeed(float speed) {
    this->speed = speed;
}