#include <iostream>
#include "Player.h"

Player::Player(float radius, float speed, int life) : Entity(radius, speed, life) {
    setHitbox(radius);
    //shape.setFillColor(sf::Color::Blue);
}

void Player::update(sf::Time deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        mode = 1;
        spriteAnimation(48, 192, 0, 132.75, 48, 45, xtext, playerSprite);
        playerSprite.move(0, -speed * deltaTime.asSeconds());
        hitbox.move(0, -speed * deltaTime.asSeconds());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        mode = 2;
        spriteAnimation(48, 192, 0, 45.25, 48, 45, xtext, playerSprite);
        playerSprite.move(-speed * deltaTime.asSeconds(), 0);
        hitbox.move(-speed * deltaTime.asSeconds(), 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        mode = 3;
        spriteAnimation(48, 192, 0, 0, 48, 45, xtext, playerSprite);
        playerSprite.move(0, speed * deltaTime.asSeconds());
        hitbox.move(0, speed * deltaTime.asSeconds());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        mode = 4;
        spriteAnimation(48, 192, 0, 90.5, 48, 45, xtext, playerSprite);
        playerSprite.move(speed * deltaTime.asSeconds(), 0);
        hitbox.move(speed * deltaTime.asSeconds(), 0);
    }
}

void Player::Attack1(Entity* target) {
    if (target) {
        sf::Vector2f playerPosition = getPosition();
        sf::Vector2f targetPosition = target->getPosition();

        float distance = std::sqrt((playerPosition.x - targetPosition.x) * (playerPosition.x - targetPosition.x) +
            (playerPosition.y - targetPosition.y) * (playerPosition.y - targetPosition.y));

        float thresholdDistance = 10.0f;

        if (distance <= thresholdDistance) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            target->setLife(target->getLife() - 10);
            }
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && animationClockA.getElapsedTime().asSeconds() >= animationSpeedA) {
        Attacking = true;
            
        if (mode == 3 && Attacking == true) {
            spriteAnimation(48, 432, 192, 0, 48, 45, atext, playerSprite);
        }
        if (mode == 2 && Attacking == true) {
            spriteAnimation(48, 432, 192, 45.25, 48, 45, atext, playerSprite);
        }
        if (mode == 1 && Attacking == true) {
            spriteAnimation(48, 432, 192, 132, 48, 45, atext, playerSprite);
        }
        if (mode == 4 && Attacking == true) {
            spriteAnimation(49, 432, 192, 90.5, 48, 45, atext, playerSprite);
        }
        animationClockA.restart();

    }
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        Attacking = false;
    }
    std::cout << Attacking <<std::endl;
}

void Player::Death() {
    setSpeed(0.0f);
    setLife(0);
    shape.setFillColor(sf::Color::Transparent);
    setPosition(-1000.0f, -1000.0f);
}
