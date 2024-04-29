#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;

    enum ESTADOS_PERSONAJE{
        QUIETO,
        CAMINADO_ADELANTE,
        CAMINANDO_ATRAS,
        SALTANDO

    };    
class Personaje{
    private:
        //sf::CircleShape _shape;

        int pos_x;
        int pos_y;
        float velocidadX = 0.0f;
        float velocidadY = 0.0f;
        bool saltando = false;
        bool mirandoDerecha = true;

    // Variables para controlar la animación
        int frameActual = 0;
        int totalFrames = 2;
        int duracionFrame = 300; // Duración de cada frame en milisegundos
        sf::Clock relojAnimacion;
        ESTADOS_PERSONAJE _estado;
        float _velocidadSalto;
        std::vector<sf::Texture> texturasFramesDerecha;
        std::vector<sf::Texture> texturasFramesIzquierda;
        std::vector<sf::Texture> texturasFramesSalto;
        std::vector<sf::Texture> texturasFramesEstatico;
        sf::Clock relojAnimacion;
        
        
    public:
        sf::Sprite spritePersonaje;
        Personaje(){
            sf::Sprite spritePersonaje(texturasFramesEstatico[0]);
            spritePersonaje.setPosition(100, 100);            
            _estado=ESTADOS_PERSONAJE::QUIETO;
            _velocidadSalto=0;
        };

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

        void cmd(){
                carga_sprites("./sprites/derecha",texturasFramesDerecha);
                carga_sprites("./sprites/izquierda",texturasFramesIzquierda);
                carga_sprites("./sprites/salto",texturasFramesSalto);
                carga_sprites("./sprites/estatico",texturasFramesEstatico);
            //_estado=ESTADOS_PELOTA::QUIETO;
            if(_estado==ESTADOS_PERSONAJE::QUIETO){

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                    _estado=ESTADOS_PERSONAJE::SALTANDO;
                    _velocidadSalto=30;
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    _estado=ESTADOS_PERSONAJE::CAMINADO_ADELANTE;
                    //pos_x += velocidadX

                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    _estado=ESTADOS_PERSONAJE::CAMINANDO_ATRAS;
                    //pos_x -= velocidadX

                }
            }
        };

        void update(){
            switch (_estado)
            {
            case QUIETO:
                
                break;
            case CAMINADO_ADELANTE:
                velocidadX = 0.2f; // Mover hacia la derecha al presionar D
                mirandoDerecha = true;
                spritePersonaje.setTexture(texturasFramesDerecha[0]);
                spritePersonaje.move(velocidadX, velocidadY);
                
                //_estado=ESTADOS_PERSONAJE::QUIETO;
                break;
            case CAMINANDO_ATRAS:
                velocidadX = -0.2f; // Mover hacia la izquierda al presionar A
                mirandoDerecha = false;
                spritePersonaje.setTexture(texturasFramesIzquierda[0]);
                spritePersonaje.move(velocidadX, velocidadY);
                 
                break;        
            case SALTANDO:
                velocidadY = -20.0f; // Impulsar hacia arriba al saltar
                saltando = true;
                spritePersonaje.setTexture(texturasFramesSalto[0]);
                spritePersonaje.move(velocidadX, velocidadY);
                break;
            default:
                break;
            }

        };

        /*sf::CircleShape &getDraw(){
            return _shape;
        };*/

        void quieto(float x, float y){
            _estado=ESTADOS_PERSONAJE::QUIETO;
            _velocidadSalto=0;
            spritePersonaje.setPosition(x,y);
        }


};
