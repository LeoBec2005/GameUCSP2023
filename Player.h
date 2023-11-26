// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include <vector>

class Player : public Entity {
public:
    Player(float speed, int life, float damage);

    void update(sf::Time deltaTime) override;
    void draw(sf::RenderWindow& window) const ;
    void setTarget(Entity* target) override;
    void Attack1(Entity* target);
    void Death() override;

private:
    std::vector<sf::Texture> textureUpFrames;
    std::vector<sf::Texture> textureDownFrames;
    std::vector<sf::Texture> textureLeftFrames;
    std::vector<sf::Texture> textureRightFrames;

    sf::Time frameTimer;
    unsigned int currentFrame;

    void loadTextureSet(const std::string& baseFilename, std::vector<sf::Texture>& textureSet);
    Entity* target;

};

#endif