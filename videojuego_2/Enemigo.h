#include "Identidad.h"
#include <cstdlib>
#include <ctime>

class Enemigo : public Identidad {
private:
    float velocidadX;
    float velocidadY;

public:
    Enemigo(int vida, int danio, int posx, int posy, int hit_boxX, int hit_boxY);
    void movimiento(float deltaTime) override;
    void cambiarDireccion();
};



Enemigo::Enemigo(int vida, int danio, int posx, int posy, int hit_boxX, int hit_boxY)
    : Identidad(vida, danio, posx, posy, rand() % 3 - 1, rand() % 3 - 1, hit_boxX, hit_boxY), velocidadX(0.1f), velocidadY(0.1f) {
    srand(static_cast<unsigned>(time(nullptr)));
    sprite.setPosition(posx, posy);
}

void Enemigo::movimiento(float deltaTime) {
    posx += veloX * deltaTime;
    posy += veloY * deltaTime;
    sprite.setPosition(posx, posy);

    // Cambiar dirección aleatoriamente
    if (rand() % 100 < 2) { 
        cambiarDireccion();
    }
}

void Enemigo::cambiarDireccion() {
    veloX = rand() % 3 - 1;
    veloY = rand() % 3 - 1;
}
