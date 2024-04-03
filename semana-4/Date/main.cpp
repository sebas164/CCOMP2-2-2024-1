#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

int main(){
    Date d1(35,2,2020);
    Date d2(29,2,2014);
    Date d3(20,13,1500);

    d1.displayDate();
    if(d1.isLeapYear()){
        cout<<"El anio es bisiesto"<<endl;
    }else{
        cout<<"El anio no es bisiesto"<<endl;
    }
    int dia;
    cout<<"ingrese el dia"<<endl;
    cin>>dia;
    d1.setDay(dia);
    d1.displayDate();
   cout<<"-----------------------------------"<<endl;
    d2.displayDate();
    if(d2.isLeapYear()){
        cout<<"El anio es bisiesto"<<endl;
    }else{
        cout<<"El anio no es bisiesto"<<endl;
    }
    cout<<"-----------------------------------"<<endl;
    d3.displayDate();
    if(d3.isLeapYear()){
        cout<<"El anio es bisiesto"<<endl;
    }else{
        cout<<"El anio no es bisiesto"<<endl;
    }

    return 0;
}