#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"

class Enemy : public Entity {
public:
    Enemy(float radius, float speed, int life, Player& player);

    void update(sf::Time deltaTime) override;
    void Death() override;

private:
    Player& player;
};

#endif