#include<iostream>
#include<string>


class Persona {
protected:
    std::string nombre;
    int edad;
public:
    Persona(std::string n = "", int p = 0) : nombre(n), edad(p) {}

    std::string getNombre() const {
        return nombre;
    }

    void setNombre(std::string n) {
        nombre = n;
    }

    int getEdad() const {
        return edad;
    }

    void setEdad(int i) {
        edad = i;
    }

    void print(Persona *p,int i) const{
        std::cout<<p[i].getNombre()<<" "<<p[i].getEdad()<<std::endl;
    }

    void imprimir(Persona* p, int tam) {
        for (int i = 0; i < tam; i++) {
            std::cout << p[i].getNombre() << " " << p[i].getEdad() << std::endl;
        }
    }

    void ordenarEdad(Persona* p, int tam) {
        for (int i = 0; i < tam; i++) {
            for (int j = i + 1; j < tam; j++) {
                if (p[i].getEdad() > p[j].getEdad()) {
                    Persona aux = p[i];
                    p[i] = p[j];
                    p[j] = aux;
                }
            }
        }
    }    


    void ordenarNombre(Persona* p, int tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (p[i].getNombre() > p[j].getNombre()) {
                Persona aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }


};