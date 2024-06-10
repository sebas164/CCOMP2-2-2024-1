#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>


class Entidad{
    public:
         void carga_sprites(const std::string& basePath, std::vector<sf::Texture>& texturas,int tam);

};

void Entidad::carga_sprites(const std::string& basePath, std::vector<sf::Texture>& texturas,int tam) {
    for (int i = 0; i < tam; ++i) {
        std::string nombreArchivo = basePath + std::to_string(i) + ".png";
        sf::Texture texturaFrame;
        if (!texturaFrame.loadFromFile(nombreArchivo)) {
            std::cerr << "Error cargando " << nombreArchivo << std::endl;
        }
        texturas.push_back(texturaFrame);
    }
}