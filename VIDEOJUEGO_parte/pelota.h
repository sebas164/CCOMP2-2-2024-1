#include <SFML\Graphics.hpp>

    enum ESTADOS_PELOTA{
        QUIETO,
        CAMINADO_ADELANTE,
        CAMINANDO_ATRAS,
         SALTANDO

    };    
class Pelota{
    private:
        sf::CircleShape _shape;
        ESTADOS_PELOTA _estado;
        float _velocidadSalto;
    public:

        Pelota(){
            _shape.setFillColor(sf::Color::Magenta);
            _shape.setRadius(20);
            _shape.setPosition(100,100);
            _estado=ESTADOS_PELOTA::QUIETO;
            _velocidadSalto=0;
        };

        void cmd(){
            //_estado=ESTADOS_PELOTA::QUIETO;
            if(_estado==ESTADOS_PELOTA::QUIETO){

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                    _estado=ESTADOS_PELOTA::SALTANDO;
                    _velocidadSalto=30;
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    _estado=ESTADOS_PELOTA::CAMINADO_ADELANTE;
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    _estado=ESTADOS_PELOTA::CAMINANDO_ATRAS;

                }
            }
        };

        void update(){
            switch (_estado)
            {
            case QUIETO:
                
                break;
            case CAMINADO_ADELANTE:
                _shape.move(3,0);/* code */
                //_estado=ESTADOS_PELOTA::QUIETO;
                break;
            case CAMINANDO_ATRAS:
                 _shape.move(-3,0);
                // _estado=ESTADOS_PELOTA::QUIETO;
                /* code */
                break;        
            case SALTANDO:
                _velocidadSalto-=2;//quito gravedad
                _shape.move(0,-_velocidadSalto);
                /* code */
                break;
            default:
                break;
            }

        };

        sf::CircleShape &getDraw(){
            return _shape;
        };

        void quieto(float x, float y){
            _estado=ESTADOS_PELOTA::QUIETO;
            _velocidadSalto=0;
            _shape.setPosition(x,y);
        }


};
