#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Entity.h"

class Player : public Entity {
public:
    Player(float radius, float speed, int life);
    void update(sf::Time deltaTime) override;
    void Attack1(Entity* target);
    void Death() override;

private:
    Entity* target; 
    float xtext = 0.0f;
    float atext = 192.0f;
    bool Attacking;
    int mode = 3;
    float animationSpeedA = 0.5;
    sf::Clock animationClockA;
};

#endif
