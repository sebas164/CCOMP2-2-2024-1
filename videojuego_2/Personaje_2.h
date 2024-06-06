// Personaje.cpp

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

class Personaje {
private:
    int vida;
    int danio;
    int posx;
    int posy;
    int veloX;
    int veloY;
    int hit_boxX;
    int hit_boxY;

    std::vector<sf::Texture> texturasFramesDerecha;
    std::vector<sf::Texture> texturasFramesIzquierda;
    std::vector<sf::Texture> texturasFramesSalto;
    std::vector<sf::Texture> texturasFramesEstatico;
    sf::Sprite spritePersonaje;

    int frameActual;
    int totalFrames;
    int duracionFrame;
    sf::Clock relojAnimacion;
    float velocidadX;
    float velocidadY;
    bool saltando;
    bool mirandoDerecha;

public:
    Personaje();
    void carga_sprites(const std::string& basePath, std::vector<sf::Texture>& texturas);
    void manejarEvento(const sf::Event& evento);
    void actualizar(float deltaTime);
    void draw(sf::RenderWindow& ventana);
};

Personaje::Personaje()
    : vida(100), danio(10), posx(400), posy(300), veloX(0), veloY(0), hit_boxX(50), hit_boxY(50),
      frameActual(0), totalFrames(2), duracionFrame(300), velocidadX(0.0f), velocidadY(0.0f), saltando(false), mirandoDerecha(true) {
    carga_sprites("./sprites/derecha", texturasFramesDerecha);
    carga_sprites("./sprites/izquierda", texturasFramesIzquierda);
    carga_sprites("./sprites/salto", texturasFramesSalto);
    carga_sprites("./sprites/estatico", texturasFramesEstatico);

    spritePersonaje.setTexture(texturasFramesEstatico[0]);
    spritePersonaje.setPosition(posx, posy);
}

void Personaje::carga_sprites(const std::string& basePath, std::vector<sf::Texture>& texturas) {
    for (int i = 0; i < 2; ++i) {
        std::string nombreArchivo = basePath + std::to_string(i) + ".png";
        sf::Texture texturaFrame;
        if (!texturaFrame.loadFromFile(nombreArchivo)) {
            std::cerr << "Error cargando " << nombreArchivo << std::endl;
        }
        texturas.push_back(texturaFrame);
    }
}

void Personaje::manejarEvento(const sf::Event& evento) {
    if (evento.type == sf::Event::KeyPressed) {
        if (evento.key.code == sf::Keyboard::W && !saltando) {
            velocidadY = -25.0f;
            saltando = true;
            spritePersonaje.setTexture(texturasFramesSalto[0]);
        } else if (evento.key.code == sf::Keyboard::D) {
            velocidadX = 0.2f;
            mirandoDerecha = true;
            spritePersonaje.setTexture(texturasFramesDerecha[0]);
        } else if (evento.key.code == sf::Keyboard::A) {
            velocidadX = -0.2f;
            mirandoDerecha = false;
            spritePersonaje.setTexture(texturasFramesIzquierda[0]);
        }
    } else if (evento.type == sf::Event::KeyReleased) {
        if (evento.key.code == sf::Keyboard::D || evento.key.code == sf::Keyboard::A) {
            velocidadX = 0.0f;
            spritePersonaje.setTexture(texturasFramesEstatico[0]);
        }
    }
}

void Personaje::actualizar(float deltaTime) {
    if (spritePersonaje.getPosition().y < 300) {
        velocidadY += 0.3f;
    } else {
        velocidadY = 0.0f;
        saltando = false;
        
    }

    spritePersonaje.move(velocidadX, velocidadY);

    if (relojAnimacion.getElapsedTime().asMilliseconds() >= duracionFrame) {
        frameActual = (frameActual + 1) % totalFrames;
        if (mirandoDerecha) {
            if (saltando) {
                spritePersonaje.setTexture(texturasFramesSalto[frameActual]);
            } else if (velocidadX != 0.0f) {
                spritePersonaje.setTexture(texturasFramesDerecha[frameActual]);
            } else {
                spritePersonaje.setTexture(texturasFramesEstatico[frameActual]);
            }
        } else {
            if (saltando) {
                spritePersonaje.setTexture(texturasFramesSalto[frameActual]);
            } else if (velocidadX != 0.0f) {
                spritePersonaje.setTexture(texturasFramesIzquierda[frameActual]);
            } else {
                spritePersonaje.setTexture(texturasFramesEstatico[frameActual]);
            }
        }
        relojAnimacion.restart();
    }
}

void Personaje::draw(sf::RenderWindow& ventana) {
    ventana.draw(spritePersonaje);
}