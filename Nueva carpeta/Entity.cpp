// entity.cpp
#include <iostream>
#include "Entity.h"

Entity::Entity(float radius, float speed, int life) : radius(radius), speed(speed), life(life) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::White);
    playertexture.loadFromFile("assets/playersprites.png");
    playerSprite.setTexture(playertexture);
    playerSprite.setScale(6, 6);
    playerSprite.setTextureRect(sf::IntRect(0, 0, 25.25, 32.25));
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
    this->speed = speed;
}

sf::Vector2f Entity::getPosition() const {
    return playerSprite.getPosition();
}

void Entity::setPosition(float x, float y) {
    playerSprite.setPosition(x, y);
    hitbox.setPosition(x, y);
}

void Entity::draw(sf::RenderWindow& window) {
    window.draw(hitbox);
    window.draw(playerSprite);
}

void Entity::spriteAnimation(float a, float b, float c, float d, float e, float f, float& xtext,sf::Sprite& Sprite) {
    if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
        xtext += a;
        if (xtext >= b)
            xtext = c;
        Sprite.setTextureRect(sf::IntRect(xtext, d, e, f));
        animationClock.restart();
    }
    std::cout<<xtext<<std::endl;
}