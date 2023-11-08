#ifndef player_h
#define player_h
#pragma once
using namespace std;

class Player { 
private:
    sf::CircleShape circle;
    sf::Texture playertexture;
    sf::Sprite playerSprite;
    float xtexture = 0;
    float attacktexture = 101;
    sf::Clock animationClock;
    bool Attacking;
    float animationSpeed = 0.2;
    float x = 400;
    float y = 300;
    float speed = 0.5;
    int mode = 3;

public:
Player() {
    circle.setRadius(50);
    circle.setFillColor(sf::Color::Blue);
    playertexture.loadFromFile("assets/playersprites.png");
    playerSprite.setTexture(playertexture);
    playerSprite.setScale(6,6);
    playerSprite.setTextureRect(sf::IntRect(0, 0, 25.25, 32.25));
    bool Attacking(false);
	}

void move(int width, int height) {
    // mode w = 1,a = 2, s = 3, d = 4
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        mode = 1;
        y -= speed;
        if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
            xtexture += 25.5;
            if (xtexture >= 101)
                xtexture = 0;
            playerSprite.setTextureRect(sf::IntRect(xtexture, 96.75, 22, 32.25));
            animationClock.restart();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        mode = 2;
        x -= speed;
        if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
            xtexture += 25.5;
            if (xtexture >= 101)
                xtexture = 0;
            playerSprite.setTextureRect(sf::IntRect(xtexture, 32.25, 20, 32.25));
            animationClock.restart();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        mode = 3;
        y += speed;
        if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
            xtexture += 25.5;
            if (xtexture >= 101)
                xtexture = 0;
            playerSprite.setTextureRect(sf::IntRect(xtexture, 0, 22, 32.25));
            animationClock.restart();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        mode = 4;
        x += speed;
        if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
            xtexture += 25.5;
            if (xtexture >= 101)
                xtexture = 0;
            playerSprite.setTextureRect(sf::IntRect(xtexture, 64.5, 20, 32.25));
            animationClock.restart();
        }
    }
    playerSprite.setPosition(x, y);
    circle.setPosition(x, y);

    std::cout << std::fixed << std::setprecision(1);
    cout << "x:" << x <<"   y:" << y << "   attack:" <<boolalpha<< Attacking <<"    modo:"<<mode << "    textures:"<<xtexture<<"    "<< attacktexture << endl;
    std::cout << std::defaultfloat;
    if (x == width-125) {
        x--;
    }
    if (x == 0) {
        x++;
    }
    if (y == 0) {
        y++;
    }
    if (y == height-200) {
        y--;
    }
}

void attack() {
    // mode w = 1,a = 2, s = 3, d = 4
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        playerSprite.setPosition(x-100, y-50);
        Attacking = true;
        if (mode == 3) {
            if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
                attacktexture += 47;
                if (attacktexture >= 330)
                    attacktexture = 101;
                playerSprite.setTextureRect(sf::IntRect(attacktexture, 0, 47, 45));
                animationClock.restart();
            }
		}
        if (mode == 2) {
            if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
                attacktexture += 47;
                if (attacktexture >= 330)
                    attacktexture = 101;
                playerSprite.setTextureRect(sf::IntRect(attacktexture, 45.25, 47, 45));
                animationClock.restart();
            }
        }
        if (mode == 1) {
            if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
                attacktexture += 48;
                if (attacktexture >= 330)
                    attacktexture = 101;
                playerSprite.setTextureRect(sf::IntRect(attacktexture, 135.75, 48, 45));
                animationClock.restart();
            }
        }
        if (mode == 4) {
            if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
                attacktexture += 50;
                if (attacktexture >= 330)
                    attacktexture = 101;
                playerSprite.setTextureRect(sf::IntRect(attacktexture, 90.5, 50, 45));
                animationClock.restart();
            }
        }
    }
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        Attacking = false;
    }   
}



void draw(sf::RenderWindow& window) {
    window.draw(playerSprite);
    //window.draw(circle);
}

};
#endif 