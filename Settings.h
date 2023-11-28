#pragma once
#ifndef SETTINGS_AND_HEALTHBAR_H
#define SETTINGS_AND_HEALTHBAR_H

#include <SFML/Graphics.hpp>

class Settings {
public:
    static const int Width = 1500;
    static const int Height = 800;
    void draw(sf::RenderWindow& window);
    Settings (int maxHealth);
    void update(int currentHealth);

private:
    int maxHealth;
    int currentHealth;
    sf::RectangleShape bar;
};

#endif