
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class Obstaculo : public sf::Drawable, public Collisionable {
private:
    sf::RectangleShape shape;

public:
    Obstaculo(float x, float y, float width, float height) {
        shape.setPosition(x, y);
        shape.setSize({width, height});
        shape.setFillColor(sf::Color::Red);
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(shape, states);
    }

    sf::FloatRect getBounds() const override {
        return shape.getGlobalBounds();
    }
};
