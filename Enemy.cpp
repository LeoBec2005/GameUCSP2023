#include "enemy.h"
#include <iostream>

Enemy::Enemy(float speed, int life, float damage)
    : Entity("assets/playersprites.png", speed, life, damage),
    textureUpFrames(),
    textureDownFrames(),
    textureLeftFrames(),
    textureRightFrames(),
    frameTimer(sf::Time::Zero),  // Inicializar el temporizador a cero
    currentFrame(0) {
    // Cargar texturas para diferentes direcciones
    loadTextureSet("assets/playersprite_up", textureUpFrames);
    loadTextureSet("assets/playersprite_down", textureDownFrames);
    loadTextureSet("assets/playersprite_left", textureLeftFrames);
    loadTextureSet("assets/playersprite_right", textureRightFrames);

    // Configurar el sprite inicial
    sprite.setTexture(textureDownFrames[currentFrame]);
}

void Enemy::loadTextureSet(const std::string& baseFilename, std::vector<sf::Texture>& textureSet) {
    for (int i = 1; i <= 4; ++i) {
        sf::Texture texture;
        std::string filename = baseFilename + std::to_string(i) + ".png";
        if (texture.loadFromFile(filename)) {
            textureSet.push_back(texture);
        }
        else {
            // Manejar el error de carga de textura, por ejemplo, imprimir un mensaje
            std::cout << "Error al cargar la textura: " << filename << std::endl;
        }
    }
}

void Enemy::update(sf::Time deltaTime) {
    sf::Vector2f direction = target->getPosition() - getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    // Normalizar la dirección si no es cero
    if (length != 0) {
        direction /= length;
    }

    // Mover el enemigo hacia el jugador
    sprite.move(direction * speed * deltaTime.asSeconds());
    hitbox.move(direction * speed * deltaTime.asSeconds());

    // Cambiar de sprite según la dirección del movimiento
    if (std::abs(direction.x) > std::abs(direction.y)) {
        if (direction.x > 0) {
            // Mover hacia la derecha
            sprite.setTexture(textureRightFrames[currentFrame]);
        }
        else {
            // Mover hacia la izquierda
            sprite.setTexture(textureLeftFrames[currentFrame]);
        }
    }
    else {
        if (direction.y > 0) {
            // Mover hacia abajo
            sprite.setTexture(textureDownFrames[currentFrame]);
        }
        else {
            // Mover hacia arriba
            sprite.setTexture(textureUpFrames[currentFrame]);
        }
    }

    // Incrementar el índice del frame actual (cambia el sprite) cada cierto tiempo
    frameTimer += deltaTime;
    if (frameTimer >= sf::seconds(0.2f)) {
        currentFrame = (currentFrame + 1) % 4;  // Considerando 4 frames por dirección
        frameTimer = sf::Time::Zero;  // Reiniciar el temporizador después de cambiar de sprite
    }

    // Resto de la lógica de actualización
}

void Enemy::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
    // Dibujar hitbox (opcional)
    // window.draw(hitbox);
}

void Enemy::setTarget(Entity* target) {
    this->target = target;
}

void Enemy::Attack1(Entity* target) {
    if (target) {
        sf::Vector2f playerPosition = getPosition();
        sf::Vector2f targetPosition = target->getPosition();

        float distance = std::sqrt((playerPosition.x - targetPosition.x) * (playerPosition.x - targetPosition.x) +
            (playerPosition.y - targetPosition.y) * (playerPosition.y - targetPosition.y));

        float thresholdDistance = 10.0f;

        if (distance <= thresholdDistance) {
           target->setLife(target->getLife() - damage);
        }
    }
}


void Enemy::Death() {
    sprite.setTexture(sf::Texture()); // Establece una textura vacía
    setSpeed(0.0f);
    setDamage(0.0f);
}
