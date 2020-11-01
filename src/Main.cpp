//
// Created by Administrator on 2020/10/31.
//
#include <iostream>
#include "GL/glew.h"
#include "SFML/Graphics.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    GLenum err = glewInit();
    if (GLEW_OK != err) {
        std::cout << "Error: " << glewGetErrorString(err) << std::endl;
    }
    std::cout << "Glew init successfully" << std::endl;

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
