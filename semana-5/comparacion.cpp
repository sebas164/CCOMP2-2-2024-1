#include<iostream>
#include <string>
using namespace std;

int main(){

    string cadena="aba saba naba caba";
    string cadena2="aba";
    int tam=0;
    cout<<tam;

    for(int i=0;i<cadena.size();i++){
        
        int val=static_cast<int>(cadena.at(i));
        int val2=static_cast<int>(cadena2.at(tam));
        tam++;
        

        if(tam==cadena2.size()-1){           
            tam=0;            

        }

    }




}