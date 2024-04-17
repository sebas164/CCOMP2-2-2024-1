#include <iostream>
using namespace std;

int potencia(int base,int exponente){
    int resul=1;
    for(int i=0;i<exponente;i++){
        resul*=base;
    }
    return resul;
}

int main(){
    int base;
    int exponente;
    cin>>base;
    cin>>exponente;
    cout<<potencia(base,exponente);
}