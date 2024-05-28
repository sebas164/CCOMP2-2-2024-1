
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void carga_sprites(const string a, vector<sf::Texture> &texturas) {
    for (int i = 0; i < 2; ++i) {
        string nombreArchivo = a + to_string(i) + ".png";
        sf::Texture texturaFrame;
        if (!texturaFrame.loadFromFile(nombreArchivo)) {
            // Manejar error si la textura no se puede cargar
                cout<<"no carga "<<nombreArchivo<<endl;
            }
             
        texturas.push_back(texturaFrame);
    }
}


int main() {
    // Crear una ventana de SFML
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Animación de personaje con SFML");

    // Vector para almacenar las texturas de los frames del personaje
    std::vector<sf::Texture> texturasFramesDerecha;
    std::vector<sf::Texture> texturasFramesIzquierda;
    std::vector<sf::Texture> texturasFramesSalto;
    std::vector<sf::Texture> texturasFramesEstatico;
    

    // Cargar las imágenes del sprite del personaje como texturas para movimientos a la derecha

    carga_sprites("./sprites/derecha",texturasFramesDerecha);
    carga_sprites("./sprites/izquierda",texturasFramesIzquierda);
    carga_sprites("./sprites/salto",texturasFramesSalto);
    carga_sprites("./sprites/estatico",texturasFramesEstatico);

sf::Sprite spritePersonaje(texturasFramesEstatico[0]);
    spritePersonaje.setPosition(400, 300);
    float velocidadX = 0.0f;
    float velocidadY = 0.0f;
    bool saltando = false;
    bool mirandoDerecha = true;

    // Variables para controlar la animación
    int frameActual = 0;
    int totalFrames = 2;
    int duracionFrame = 300; // Duración de cada frame en milisegundos
    sf::Clock relojAnimacion;

    // Bucle principal del juego
    while (ventana.isOpen()) {
        // Procesar eventos
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }
            else if (evento.type == sf::Event::KeyPressed) {
                if (evento.key.code == sf::Keyboard::W && !saltando) {
                    velocidadY = -20.0f; // Impulsar hacia arriba al saltar
                    saltando = true;
                    spritePersonaje.setTexture(texturasFramesSalto[0]); // Cambiar a la animación de salto
                }
                else if (evento.key.code == sf::Keyboard::D) {
                    velocidadX = 0.2f; // Mover hacia la derecha al presionar D
                    mirandoDerecha = true;
                    spritePersonaje.setTexture(texturasFramesDerecha[0]); // Cambiar a la animación de mover derecha
                }
                else if (evento.key.code == sf::Keyboard::A) {
                    velocidadX = -0.2f; // Mover hacia la izquierda al presionar A
                    mirandoDerecha = false;
                    spritePersonaje.setTexture(texturasFramesIzquierda[0]); // Cambiar a la animación de mover izquierda
                }
            }
            else if (evento.type == sf::Event::KeyReleased) {
                if (evento.key.code == sf::Keyboard::D || evento.key.code == sf::Keyboard::A) {
                    velocidadX = 0.0f; // Detener el movimiento al soltar D o A
                    spritePersonaje.setTexture(texturasFramesEstatico[0]); // Cambiar a la animación estática
                }
            }
        }

        // Aplicar gravedad
        if (spritePersonaje.getPosition().y < 300) { // Si el personaje está en el aire
            velocidadY += 0.5f; // Aplicar gravedad
        }
        else { // Si el personaje está en el suelo
            velocidadY = 0.0f;
            saltando = false;
        }

        // Actualizar la posición vertical y horizontal del personaje
        spritePersonaje.move(velocidadX, velocidadY);

        // Actualizar la animación del personaje
        if (relojAnimacion.getElapsedTime().asMilliseconds() >= duracionFrame) {
            frameActual = (frameActual + 1) % totalFrames;
            if (mirandoDerecha) { // Si el personaje está mirando a la derecha
                if (saltando) { // Si el personaje está saltando
                    spritePersonaje.setTexture(texturasFramesSalto[frameActual]);
                }
                else if (velocidadX != 0.0f) { // Si el personaje está en movimiento horizontal
                    spritePersonaje.setTexture(texturasFramesDerecha[frameActual]);
                }
                else { // Si el personaje está estático
                    spritePersonaje.setTexture(texturasFramesEstatico[frameActual]);
                }
            }
            else { // Si el personaje está mirando a la izquierda
                if (saltando) { // Si el personaje está saltando
                    spritePersonaje.setTexture(texturasFramesSalto[frameActual]);
                }
                else if (velocidadX != 0.0f) { // Si el personaje está en movimiento horizontal
                    spritePersonaje.setTexture(texturasFramesIzquierda[frameActual]);
                }
                else { // Si el personaje está estático
                    spritePersonaje.setTexture(texturasFramesEstatico[frameActual]);
                }
            }
            relojAnimacion.restart();
        }

        // Limpiar la ventana
        ventana.clear();

        // Dibujar el sprite del personaje
        ventana.draw(spritePersonaje);

        // Mostrar la ventana
        ventana.display();
    }

    return EXIT_SUCCESS;
}







