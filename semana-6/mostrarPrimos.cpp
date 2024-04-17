#include <iostream>
using namespace std;
bool primo(int n){
    bool bandera=true;
    

    for(int i=2;i*i<=n;i++){
        if(n%i==0){
           bandera=false;
        }
    }
    
    if(bandera && n>1){
        return bandera=true;

    }else{
        return bandera=false;
    }
}

void printPrimos(int n){
    for(int i=2;i<=n;i++){
        if(primo(i)){
            cout<<i<<" ";
        }
        else{
            continue;
        }
    }
}

int main(){

    int num;
    cout<<"Ingrese un numeros: ";
    cin>>num;
    cout<<"Los numeros primos de este numero son: "<<endl;
    if(num>1){
        printPrimos(num);

    }
    else{
        cout<<"No tiene"<<endl;
    }

}