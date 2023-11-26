#include "Settings.h"

Settings::Settings(int maxHealth) : maxHealth(maxHealth), currentHealth(maxHealth) {
    bar.setSize(sf::Vector2f(200.0f, 20.0f));
    bar.setFillColor(sf::Color::Green);
    bar.setPosition(10.0f, Settings::Height - 30.0f);
}

void Settings::update(int currentHealth) {
    this->currentHealth = currentHealth;

    float barWidth = static_cast<float>(currentHealth) / maxHealth * (Settings::Width - 500.0f); 
    bar.setSize(sf::Vector2f(barWidth, 20.0f));
}


void Settings::draw(sf::RenderWindow& window) {
    window.draw(bar);
}