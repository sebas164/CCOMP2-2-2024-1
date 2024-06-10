
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Entidad.h"
#include "Oobstaculo.h"
#include "Collisionable.h"
#include <string>
#include <vector>



class Personaje : public Entidad, public sf::Drawable, public Collisionable{
private:
    std::vector<sf::Texture> texturasFramesDerecha;
    std::vector<sf::Texture> texturasFramesIzquierda;
    std::vector<sf::Texture> texturasFramesSalto;
    std::vector<sf::Texture> texturasFramesEstatico;
    sf::Sprite _spritePersonaje;
    
    sf::Vector2f _velocity = {0.2, 0.2};
    sf::Vector2f _gravity = {0, 0.005}; // Aceleración de la gravedad
    sf::Vector2f _currentVelocity = {0, 0};
    bool _isJumping = false;
    bool _onGround = false;
    int vida;
    int danio;
    sf::Clock animClock;
    int currentFrameDerecha = 0;
    int currentFrameIzquierda = 0;
    Obstaculo *obstacle;

public:
    Personaje(int vida = 100, int danio = 10) {    
        _spritePersonaje.setOrigin(_spritePersonaje.getGlobalBounds().width / 2, _spritePersonaje.getGlobalBounds().height);        
        Entidad::carga_sprites("./sprites/derecha", texturasFramesDerecha, 2);
        Entidad::carga_sprites("./sprites/izquierda", texturasFramesIzquierda, 2);
        Entidad::carga_sprites("./sprites/salto", texturasFramesSalto, 1);
        Entidad::carga_sprites("./sprites/estatico", texturasFramesEstatico, 2);
        _spritePersonaje.setPosition(400, 300);
    }

    void update() {
        sf::Vector2f velocity = {0, 0};
        float animSpeed = 0.2f;

        // Aplicar la gravedad
        if (!_onGround) {
            _currentVelocity += _gravity;
        } else {
            _currentVelocity.y = 0;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && _onGround) {
            _currentVelocity.y = -_velocity.y * 7; // Impulso de salto
            _isJumping = true;
            _onGround = false;
            _spritePersonaje.setTexture(texturasFramesSalto[0]);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            velocity.x = -_velocity.x;
            if (animClock.getElapsedTime().asSeconds() > animSpeed) {
                currentFrameIzquierda = (currentFrameIzquierda + 1) % texturasFramesIzquierda.size();
                _spritePersonaje.setTexture(texturasFramesIzquierda[currentFrameIzquierda]);
                animClock.restart();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            velocity.x = _velocity.x;
            if (animClock.getElapsedTime().asSeconds() > animSpeed) {
                currentFrameDerecha = (currentFrameDerecha + 1) % texturasFramesDerecha.size();
                _spritePersonaje.setTexture(texturasFramesDerecha[currentFrameDerecha]);
                animClock.restart();
            }
        }
         // Verificar colisiones con obstáculos
        /*if (isCollision(*obstacle) && _currentVelocity.y > 0) {
            // Aterrizar si hay colisión con el obstáculo por debajo
            _spritePersonaje.setPosition(
                _spritePersonaje.getPosition().x,
                obstacle->getBounds().top - _spritePersonaje.getGlobalBounds().height
            );
            _isJumping = false; // El personaje deja de saltar
            _currentVelocity.y = 0; // Detener el movimiento vertical
            _onGround = true; // Indicar que el personaje está en el suelo
        }*/
       if (isCollision(*obstacle) && _currentVelocity.y > 0) {
            // Aterrizar si hay colisión con el obstáculo por debajo
            _spritePersonaje.setPosition(_spritePersonaje.getPosition().x, obstacle->getBounds().top-_spritePersonaje.getGlobalBounds().height);
            _isJumping = false; // El personaje deja de saltar
            _currentVelocity.y = 0; // Detener el movimiento vertical
            _onGround = true; // Indicar que el personaje está en el suelo
        }
        _spritePersonaje.move(velocity);
        _spritePersonaje.move(0, _currentVelocity.y);

        // Colisiones con los bordes de la ventana
        if (_spritePersonaje.getPosition().x < 0) {
            _spritePersonaje.setPosition(0, _spritePersonaje.getPosition().y);
        }
        if (_spritePersonaje.getPosition().y < 0) {
            _spritePersonaje.setPosition(_spritePersonaje.getPosition().x, 0);
            _currentVelocity.y = 0;
        }
        if (_spritePersonaje.getPosition().y + _spritePersonaje.getGlobalBounds().height > 400) {
            _spritePersonaje.setPosition(_spritePersonaje.getPosition().x, 400 - _spritePersonaje.getGlobalBounds().height);
            _currentVelocity.y = 0;
            _onGround = true;
            _isJumping = false;
        }
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_spritePersonaje, states);
    }

    sf::FloatRect getBounds() const override {
        return _spritePersonaje.getGlobalBounds();
        }
};


/*class Personaje:public Entidad, public sf::Drawable{
    private:
               
        std::vector<sf::Texture> texturasFramesDerecha;
        std::vector<sf::Texture> texturasFramesIzquierda;
        std::vector<sf::Texture> texturasFramesSalto;
        std::vector<sf::Texture> texturasFramesEstatico;
        sf::Sprite _spritePersonaje;
        
        sf::Vector2f _velocity={.2,.2};
        int vida;
        int danio;
        sf::Clock animClock;
        int currentFrameDerecha = 0;
        int currentFrameIzquierda = 0;
    public:
        Personaje(int vida=100,int danio=10){    
            _spritePersonaje.setOrigin(_spritePersonaje.getGlobalBounds().width /2,_spritePersonaje.getGlobalBounds().height);        
            Entidad::carga_sprites("./sprites/derecha", texturasFramesDerecha,2);
            Entidad::carga_sprites("./sprites/izquierda", texturasFramesIzquierda,2);
            Entidad::carga_sprites("./sprites/salto", texturasFramesSalto,1);
            Entidad::carga_sprites("./sprites/estatico", texturasFramesEstatico,2);
             _spritePersonaje.setPosition(400, 300);
        }

        void update() {
            sf::Vector2f velocity={0,0};
            float animSpeed = 0.2f;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                velocity.y = -_velocity.y;
                _spritePersonaje.setTexture(texturasFramesSalto[0]);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                velocity.x = -_velocity.x;
                if (animClock.getElapsedTime().asSeconds() > animSpeed) {
                    currentFrameIzquierda = (currentFrameIzquierda + 1) % texturasFramesIzquierda.size();
                    _spritePersonaje.setTexture(texturasFramesIzquierda[currentFrameIzquierda]);
                    animClock.restart();
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                velocity.x = _velocity.x;
                if (animClock.getElapsedTime().asSeconds() > animSpeed) {
                    currentFrameDerecha = (currentFrameDerecha + 1) % texturasFramesDerecha.size();
                    _spritePersonaje.setTexture(texturasFramesDerecha[currentFrameDerecha]);
                    animClock.restart();
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                velocity.y = _velocity.y;
                _spritePersonaje.setTexture(texturasFramesEstatico[0]);
            }

            _spritePersonaje.move(velocity);

            if(_spritePersonaje.getPosition().x<0){
                _spritePersonaje.setPosition(0,_spritePersonaje.getPosition().y);
            }
            if(_spritePersonaje.getPosition().y<0){
                _spritePersonaje.setPosition(_spritePersonaje.getPosition().x,0);
            }
            if(_spritePersonaje.getPosition().y+_spritePersonaje.getGlobalBounds().height>400){
                _spritePersonaje.setPosition(_spritePersonaje.getPosition().x,400-_spritePersonaje.getGlobalBounds().height);
            }
            

            /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                velocity.y=-_velocity.y;
                _spritePersonaje.setTexture(texturasFramesSalto[0]);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                velocity.x=-_velocity.x;
                _spritePersonaje.setTexture(texturasFramesIzquierda[0]);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                velocity.x=_velocity.x;
                _spritePersonaje.setTexture(texturasFramesDerecha[0]);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                velocity.y=_velocity.y;
                _spritePersonaje.setTexture(texturasFramesEstatico[0]);
            //}


           

        }       

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
            target.draw(_spritePersonaje,states);
        }
};*/
