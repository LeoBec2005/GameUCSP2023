#include "entity.h"

Entity::Entity(const std::string& texturePath, float speed, int life, float damage)
    : speed(speed), life(life), damage(damage) {
    if (!texture.loadFromFile(texturePath)) {
        // Manejar el error si no se puede cargar la textura
    }

    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);

    hitbox.setSize(sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height));
    hitbox.setOrigin(hitbox.getLocalBounds().width / 2, hitbox.getLocalBounds().height / 2);
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