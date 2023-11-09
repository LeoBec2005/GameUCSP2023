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
    float attacktexture = 192;
    sf::Clock animationClock;
    bool Attacking;
    float animationSpeed = 0.2;
    float x = 400;
    float y = 300;
    float speed = 0.5;
    int mode = 3;
    float radius;
    //float speed;
    int life;
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


void spritesf(float a,float b,float c,float d,float e,float f,float& xtext) {
    if (animationClock.getElapsedTime().asSeconds() >= animationSpeed) {
        xtext += a;
        if (xtext >= b)
            xtext = c;
        playerSprite.setTextureRect(sf::IntRect(xtext, d, e, f));
        animationClock.restart();
    }
}


void move(int width, int height) {
    // mode w = 1,a = 2, s = 3, d = 4
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        mode = 1;
        y -= speed;
    spritesf(48, 192,0,132.75,48,45, xtexture);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        mode = 2;
        x -= speed;
    spritesf(48, 192,0,45.25, 48, 45, xtexture);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        mode = 3;
        y += speed;
    spritesf(48, 192,0,0, 48, 45, xtexture);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        mode = 4;
        x += speed;
    spritesf(48, 192,0,90.5, 48, 45, xtexture);
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
        Attacking = true;
        if (mode == 3) {
        spritesf(48,432,192, 0, 48, 45, attacktexture);
		}
        if (mode == 2) {
        spritesf(48, 432, 192, 45.25, 48, 45, attacktexture);
        }
        if (mode == 1) {
        spritesf(48, 432, 192, 132, 48, 45, attacktexture);
        }
        if (mode == 4) {
        spritesf(49, 432, 192, 90.5, 48, 45, attacktexture);
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