#include<iostream>
#include <SFML/Graphics.hpp>
#include <iostream>

class Identidad {
protected:
    int vida;
    int danio;
    int posx;
    int posy;
    int veloX;
    int veloY;
    int hit_boxX;
    int hit_boxY;

    sf::Texture texture;
    sf::Sprite sprite;

public:
    Identidad(int vida, int danio, int posx, int posy, int veloX, int veloY, int hit_boxX, int hit_boxY) 
        : vida(vida), danio(danio), posx(posx), posy(posy), veloX(veloX), veloY(veloY), hit_boxX(hit_boxX), hit_boxY(hit_boxY) {
        sprite.setPosition(posx, posy);
    }

    virtual void carga_sprites(const string &a, vector<sf::Texture> &texturas) {
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
    /*virtual void carga_sprites(const std::string& filePath) {
        if (!texture.loadFromFile(filePath)) {
            std::cerr << "Error cargando la textura" << std::endl;
        }
        sprite.setTexture(texture);
    }*/

    virtual void movimiento(float deltaTime) {
        posx += veloX * deltaTime;
        posy += veloY * deltaTime;
        sprite.setPosition(posx, posy);
    }

    virtual void atacar() {
        // Implementar lógica de ataque
        std::cout << "Atacando con daño: " << danio << std::endl;
    }

    virtual void morir() {
        // Implementar lógica de muerte
        std::cout << "Personaje ha muerto" << std::endl;
    }

    virtual void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }
};


/*class Identidad{
    protected:
        int vida;
        int danio;
        int posx;
        int posy;
        int veloX;
        int veloY;
        int hit_boxX;
        int hit_boxY;
    public:
        void carga_sprites();
        void movimiento();
        void atacar();
        void morir();




};*/