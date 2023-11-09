#include <SFML/Graphics.hpp>
#include <iomanip> 
#include <iostream>
#include "player.h"
using namespace std;

//main
int main() {
    int width=1720; 
    int height=900; 
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML Example");

    Player player1;
    sf::Clock clock;
    
    while (window.isOpen()) {
        sf::Event event;
        sf::Time deltaTime = clock.restart();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        window.clear();

        player1.draw(window);
        player1.move(deltaTime);
        player1.attack();
        
        window.display();
    }
    return 0;
}