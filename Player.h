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
    Entity* target; // Puntero al objetivo (enemigo)
};

#endif