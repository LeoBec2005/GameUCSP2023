#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Entity {
public:
    Entity(float radius, float speed, int life);
    virtual ~Entity() = default;
    virtual void Death() = 0;

    void setHitbox(float hitboxRadius);
    void setLife(int lifeValue);
    void setSpeed(float speed);
    int getLife() const;
    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);
    virtual void update(sf::Time deltaTime) = 0;
    void draw(sf::RenderWindow& window);
    void spriteAnimation(float a, float b, float c, float d, float e, float f, float& xtext, sf::Sprite& Sprite);
    

protected:
    sf::Texture playertexture;
    sf::Sprite playerSprite;
    sf::CircleShape shape;
    sf::CircleShape hitbox;
    float radius;
    float speed;
    sf::Clock animationClock;
    float animationSpeed = 0.2;
    int life;
};

#endif
