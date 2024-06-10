#ifndef COLLISIONABLE_H
#define COLLISIONABLE_H
#include <SFML\Graphics.hpp>
#include <iostream>

class Collisionable{
      public:
          virtual sf::FloatRect getBounds() const=0;
           bool isCollision(Collisionable &obj) const{
                return getBounds().intersects(obj.getBounds());
           }
};

#endif // COLLISIONABLE_H