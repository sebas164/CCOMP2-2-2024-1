#include<iostream>
#include <string>
using namespace std;

int main(){

    string cadena="albucomu bascomu comu chomu";
    string cadena2="comu";
    int tam=0;
    int cont=0;
    cout<<tam;

    for(int i=0;i<cadena.size();i++){

        int val=static_cast<int>(cadena.at(i));
        int val2=static_cast<int>(cadena2.at(tam));
        if(val == val2){
            tam++;

            if(tam==cadena2.size()){           
                tam=0;
                cont++;            

            }
            
        }
        else{
            tam=0;
        }
        


    }
    cout<<cont;




}