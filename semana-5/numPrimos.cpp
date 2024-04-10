#include<iostream>
using namespace std;

int main(){
    int num;
    bool bandera=true;
    cin>>num;

    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            bandera=false;
        }
    }

    if(num>1 && bandera){
        cout<<"Es primo"<<endl;
    }
    else{
        cout<<"No es primo"<<endl;
    }





}