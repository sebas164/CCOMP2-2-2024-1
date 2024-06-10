
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "pelota.h"
using namespace std;

int main(){
    //inicializacion
    sf::RenderWindow window(sf::VideoMode(800,600),"Videojuego");
    window.setFramerateLimit(60);
    Pelota p;

    //game  looop
    while (window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){

            if(event.type==sf::Event::Closed){
                window.close();
            }
        }

        p.cmd();

        p.update();

        if(p.getDraw().getPosition().y >100){
            p.quieto(p.getDraw().getPosition().x,100);
        }

        window.clear();
        window.draw(p.getDraw());
        window.display();

    }
}