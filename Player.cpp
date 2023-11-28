// player.cpp
#include "player.h"
#include <iostream>

Player::Player(float speed, int life, float damage)
    : Entity(speed, life, damage),
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
    sprite.setScale(4, 4);
}

void Player::loadTextureSet(const std::string& baseFilename, std::vector<sf::Texture>& textureSet) {
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

void Player::update(sf::Time deltaTime) {
    // L�gica de actualizaci�n espec�fica del jugador aqu�
    // Actualiza la textura seg�n la direcci�n del movimiento
    if (death == false) {
        sf::Vector2f movement(0.0f, 0.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            movement.y -= 1.0f;
            sprite.setTexture(textureUpFrames[currentFrame]);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            movement.y += 1.0f;
            sprite.setTexture(textureDownFrames[currentFrame]);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            movement.x -= 1.0f;
            sprite.setTexture(textureLeftFrames[currentFrame]);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            movement.x += 1.0f;
            sprite.setTexture(textureRightFrames[currentFrame]);
        }

        // Normalizar la direcci�n si no es cero
        float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);
        if (length != 0) {
            movement /= length;
        }

        // Mover el jugador con la velocidad constante
        sprite.move(movement * speed * deltaTime.asSeconds());
        hitbox.move(movement * speed * deltaTime.asSeconds());

        // Incrementar el �ndice del frame actual (cambia el sprite) cada cierto tiempo
        frameTimer += deltaTime;
        if (frameTimer >= sf::seconds(0.2f)) {
            currentFrame = (currentFrame + 1) % 4;  // Considerando 4 frames por direcci�n
            frameTimer = sf::Time::Zero;  // Reiniciar el temporizador despu�s de cambiar de sprite
        }
    }
    else if (death == true) {
        texture.loadFromFile("assets//playersprite_death.png");
        sprite.setTexture(texture);
    }
    std::cout << death << std::endl;// Resto de la l�gica de actualizaci�n
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
    // Dibujar hitbox (opcional)
    // window.draw(hitbox);
}

void Player::setTarget(Entity* target) {
    this->target = target;
}

void Player::Attack1(Entity* target) {
    if (target) {
        sf::Vector2f playerPosition = getPosition();
        sf::Vector2f targetPosition = target->getPosition();

        float distance = std::sqrt((playerPosition.x - targetPosition.x) * (playerPosition.x - targetPosition.x) +
            (playerPosition.y - targetPosition.y) * (playerPosition.y - targetPosition.y));

        float thresholdDistance = 80.0f;

        if (distance <= thresholdDistance) {
           if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                target->setLife(target->getLife() - damage);
           }
        }
    }
}

void Player::Death() {
    death = true;
    setDamage(0.0f);
}
