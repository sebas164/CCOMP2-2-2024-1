#include <SFML/Graphics.hpp>
#include "Entidad.h"
#include <cmath>


class Enemy : public Entidad , public sf::Drawable{
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;
    float _speed;
    
    public:
        Enemy(int vida = 100, int danio = 10){
            
            _texture.loadFromFile("./sprites/zenemy.png");
            _sprite.setTexture(_texture);
            _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
             _sprite.setPosition(100, 100);
             _speed=0.1f;
    
        }

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
            target.draw(_sprite, states);
        }   

    void update(const sf::Vector2f& targetPosition) {
        sf::Vector2f targetCenter = targetPosition + sf::Vector2f(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
        sf::Vector2f direction = targetCenter - _sprite.getPosition();
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length != 0) {
            direction /= length; // Normaliza la dirección
        }
        _velocity = direction * _speed;
        _sprite.move(_velocity);
    }

    sf::FloatRect getBounds() const {
        return _sprite.getGlobalBounds();
    }

        
};