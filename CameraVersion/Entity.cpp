// entity.cpp
#include "entity.h"

Entity::Entity(float radius, float speed, int life) : radius(radius), speed(speed), life(life) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::White);
}

void Entity::setHitbox(float hitboxRadius) {
    hitbox.setRadius(hitboxRadius);
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Green);
    hitbox.setOutlineThickness(2.0f);
}

void Entity::setLife(int lifeValue) {
    life = lifeValue;
}

int Entity::getLife() const {
    return life;
}

void Entity::setSpeed(float speed) {
    // Asigna el valor de velocidad
    this->speed = speed;
}

sf::Vector2f Entity::getPosition() const {
    return shape.getPosition();
}

void Entity::setPosition(float x, float y) {
    shape.setPosition(x, y);
    hitbox.setPosition(x, y);
}

void Entity::draw(sf::RenderWindow& window) {
    window.draw(hitbox);
    window.draw(shape);
}