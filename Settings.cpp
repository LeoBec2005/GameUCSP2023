#include "Settings.h"

Settings::Settings(int maxHealth) : maxHealth(maxHealth), currentHealth(maxHealth) {
    bar.setSize(sf::Vector2f(200.0f, 20.0f)); // Tama�o de la barra
    bar.setFillColor(sf::Color::Green);
    bar.setPosition(10.0f, Settings::Height - 30.0f); // Posici�n
}

void Settings::update(int currentHealth) {
    this->currentHealth = currentHealth;

    // Calcula el ancho de la barra en funci�n de la salud actual y el ancho de la ventana
    float barWidth = static_cast<float>(currentHealth) / maxHealth * (Settings::Width - 500.0f); // Restamos un margen de 20.0f
    bar.setSize(sf::Vector2f(barWidth, 20.0f));
}


void Settings::draw(sf::RenderWindow& window) {
    window.draw(bar);
}