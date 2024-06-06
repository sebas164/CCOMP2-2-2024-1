// main.cpp
#include <SFML/Graphics.hpp>
#include "Personaje_2.h"

int main() {
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Animación de personaje con SFML");
    ventana.setFramerateLimit(3000);

    Personaje personaje;

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }
            personaje.manejarEvento(evento);
        }

        float deltaTime = 1.0f / 60.0f;

        personaje.actualizar(deltaTime);

        ventana.clear();
        personaje.draw(ventana);
        ventana.display();
    }

    return 0;
}