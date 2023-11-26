// player.h
#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy : public Entity {
public:
    Enemy(float speed, int life, float damage);

    void update(sf::Time deltaTime) override;
    void draw(sf::RenderWindow& window) const;
    void setTarget(Entity* target) override;
    void Attack1(Entity* target) override;
    void Death() override;

private:
    std::vector<sf::Texture> textureUpFrames;
    std::vector<sf::Texture> textureDownFrames;
    std::vector<sf::Texture> textureLeftFrames;
    std::vector<sf::Texture> textureRightFrames;

    sf::Time frameTimer;
    std::size_t currentFrame;

    void loadTextureSet(const std::string& baseFilename, std::vector<sf::Texture>& textureSet);
    Entity* target;
};

#endif