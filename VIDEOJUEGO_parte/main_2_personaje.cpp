// main.cpp
#include <SFML/Graphics.hpp>
#include "Personaje_3.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 425), "SFML Personaje Example");

    Personaje personaje;
    //Obstaculo p1(200,350,80,30);

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("./sprites/jfondoGame.jpg")) {
        std::cerr << "Error al cargar la textura de fondo" << std::endl;
        return -1; // Salir si la textura no se pudo cargar
    }

    // Crear el sprite y asignar la textura
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    /*sf::Sprite image;
    sf::Texture tex;
    tex.loadFromFile("./sprites/jfondoGame.jpg");
    image.setTexture(tex);*/

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            
        }
        personaje.update();
        
        //window.draw(image);

        window.clear();
        window.draw(backgroundSprite);
        //window.draw(p1);
        window.draw(personaje); // Dibujar el personaje
        window.display();
    }

    return 0;
}

/*int main() {
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
}*/