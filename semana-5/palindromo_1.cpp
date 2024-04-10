#include<iostream>
using namespace std;

int main(){
    int num;
    int cont2=0;
    cin>>num;
    int num2=num;
    int num3=num2;
    int aux=0;
    int aux2=0;
    int palindromo=0;   
    int base=1;
    
    //saber numero de digitos
    while(num!=0){
        
        aux=num/10;         
        num=aux;
        cont2++;
    }
    
    for(int i=0;i<cont2-1;i++){
        
        base=base*10;
    }
    
    while(num2!=0){
        //contiene cociente
        aux=num2/10;
        //contiene residuo
        aux2=num2%10;
        //Numero al reves
        palindromo=palindromo+(aux2*base);
        num2=aux;
        base=base/10;
        
    } 
    cout<<palindromo <<endl;   

    if(num3==palindromo){
        cout<<"El numero es palindromo "<<endl;

    }else{
        cout<<"El numero no es palindromo"<<endl;
    }




}