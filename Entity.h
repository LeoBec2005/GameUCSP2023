// entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
    Entity(float speed, int life, float damage);
    virtual ~Entity() = default;

    virtual void Death() = 0;

    void setHitbox(float hitboxRadius);
    void setLife(int lifeValue);
    void setDamage(int damageValue);
    void setSpeed(float speed);
    int getLife() const;
    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);
    virtual void update(sf::Time deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window);
    virtual void setTarget(Entity* target) = 0;
    virtual void Attack1(Entity* target) = 0;


protected:
    sf::Sprite sprite;
    sf::Texture texture; // Agregamos la textura aqu�
    sf::RectangleShape hitbox;
    float speed;
    int life;
    float damage;
};

#endif