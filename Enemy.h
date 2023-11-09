#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"

class Enemy : public Entity {
public:
    Enemy(float radius, float speed, int life);
    void update(sf::Time deltaTime); // Actualizamos la funci�n update sin el par�metro target
    void setTarget(Entity* target); // Nueva funci�n para establecer el objetivo
    void Attack1(Entity* target);
    void Death() override;

private:
    Entity* target;
};

#endif