#include<iostream>
#include<string>
#include "Persona.h"


int main() {
    const int tam = 10;

    Persona* persona = new Persona[tam];
    persona[0] = Persona("a", 0);
    persona[1] = Persona("b", 1);
    persona[2] = Persona("c", 2);
    persona[3] = Persona("d", 3);
    persona[4] = Persona("e", 4);
    persona[5] = Persona("f", 5);
    persona[6] = Persona("g", 6);
    persona[7] = Persona("h", 7);
    persona[8] = Persona("i", 8);
    persona[9] = Persona("j", 9);

    for (int i = 0; i < tam; i++) {
        std::string nombre;
        int edad;
        std::cout<<"ingrese el nombre de persona "<<i<<" ";
        std::getline(std::cin, nombre);
        persona[i].setNombre(nombre);
        std::cout<<"ingrese la edad de persona "<<i<<" ";
        std::cin >> edad;
        persona[i].setEdad(edad);
        std::cin.ignore();
    }
    std::cout<<"Imprimo los nombres y edades "<<std::endl;
    persona->imprimir(persona, tam);

    Persona* ptr;
    ptr = persona;
    
    std::cout << "--------" << std::endl;
    std::cout << "Elementos del ultimo elemento al primero:" << std::endl;
    for (int i = tam - 1; i >= 0; i--) {
        std::cout << (ptr + i)->getNombre() << " " << (ptr + i)->getEdad() << std::endl;
    }

    std::cout << "--------" << std::endl;
    std::cout << "Elementos con indice impar:" << std::endl;
    for (int i = 0; i < tam; i++) {
        if (i % 2 != 0) {
            std::cout << (ptr + i)->getNombre() << " " << (ptr + i)->getEdad() << std::endl;
        }
    }
    std::cout << "--------" << std::endl;
    std::cout<<"Ordenar arreglo por Edad"<<std::endl;
    persona->ordenarEdad(persona,tam);
    persona->imprimir(persona,tam);

    std::cout << "--------" << std::endl;
    std::cout<<"Ordenar arreglo por Nombres"<<std::endl;
    persona->ordenarNombre(persona,tam);
    persona->imprimir(persona,tam);


    delete []persona;

    return 0;
}