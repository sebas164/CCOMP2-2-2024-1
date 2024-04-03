#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

int main(){
    string nombre;
    int edad;
    cout<<"Ingrese su nombre: "<<endl;
    getline(cin,nombre);
    cout<<"Ingrese su edad: "<<endl;
    cin>>edad;
    Student p1(nombre,edad);
    p1.getName();
    p1.getAge();
    if(p1.isOlder()){
        cout<<"El estudiante es mayor de edad"<<endl;
    }else{
        cout<<"El estudiante es menor de edad"<<endl;
    }

    cout<<"Ingrese su nombre: "<<endl;
    cin.ignore();
    getline(cin,nombre);
    cout<<"Ingrese su edad: "<<endl;
    cin>>edad;
    Student p2(nombre,edad);
    p2.getName();
    p2.getAge();
    if(p2.isOlder()){
        cout<<"El estudiante es mayor de edad"<<endl;
    }else{
        cout<<"El estudiante es menor de edad"<<endl;
    }



    return 0;
}