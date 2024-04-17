
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


class Identidad{
    protected:
        int alto;
        int vida;
        float fuerza;
        float agilidad;
        float inteligencia;
        float velocidad;
        int danio;
        int posx;
        int posy;
        int velocidad_x;
        int velocidad_y;
        
        /*string array_1[]={"der1.png","der2.png"};
        string array_2[]={"izq1.png","izq2.png"};
        string array_3[]={"lado1.png","lado2.png"};*/


    protected:

        Identidad(int alto, int vida,float fuerza, float inteligencia,float velocidad,int danio,int posx,int posy,int velocidad_x,int velocidad_y){
            alto=alto;
            vida=vida;
            fuerza=fuerza;
            inteligencia=inteligencia;
            velocidad=velocidad;
            danio=danio;
            posx=posx;
            posy=posy;
            velocidad_x=velocidad_x;
            velocidad_y=velocidad_y;


        }
        float atacar(){
            return (danio + fuerza/2);

        }

        int morir(){
            return vida = 0;

        }

        void regeneracion(int rege){

            vida = vida + rege;
            
        }
        
        void update(){


            sf::Event event;
                if (event.key.code == sf::Keyboard::Left){

                    posx -= velocidad_x;
                    
                    



                }
                else if (event.key.code == sf::Keyboard::Right){
                    posx += velocidad_x;
                }
                else if (event.key.code == sf::Keyboard::Up){
                    posy -= velocidad_y;
                }
                else if (event.key.code == sf::Keyboard::Down){
                    posy += velocidad_y;
                }



                //alto = 200;
                //ancho = 400;


               // if posicion del personaje y > alto
                    //velocidad_y = 0

        }
};

class Arma(){
    protected:
        int filo;
        int danio;
        int hitbox;

    protected:
        Arma(int filo;int danio){
            filo=filo,
            danio=danio;
        }
        float atacar(){
            return (danio + filo/2);

        }


};



int main() {


    int ancho = 600;
    int alto = 800;
    sf::Window window(sf::VideoMode(ancho, alto), "Ventana SFML");
    sf::Texture texturas[2];

    // Cargar las imágenes en las texturas del array
    if (!texturas[0].loadFromFile("imagen1.png") || !texturas[1].loadFromFile("imagen2.png")) {
        std::cerr << "Error al cargar una o más imágenes." << std::endl;
        return 1;
    }
    

    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Cerrar ventana al presionar la tecla de cerrar o Esc
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();

                Identidad p1();

            }
        }
    }
    return 0;
}

                    







            



          


                   

                        

        









