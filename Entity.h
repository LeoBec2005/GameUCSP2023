#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Entity {
public:
    Entity(float radius, float speed, int life);
    virtual ~Entity() = default; // Agregamos un destructor virtual
    virtual void Death() = 0;

    void setHitbox(float hitboxRadius);
    void setLife(int lifeValue);
    void setSpeed(float speed);
    int getLife() const;
    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);
    virtual void update(sf::Time deltaTime) = 0;
    void draw(sf::RenderWindow& window);

protected:
    sf::CircleShape shape;
    sf::CircleShape hitbox;
    float radius;
    float speed;
    int life;
};

#endif