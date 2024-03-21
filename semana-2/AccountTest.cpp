#include <iostream>
#include <string>
#include "Account.h"
#include<iostream>
using namespace std;

int main(){
    Account myAccount;
    cout<<"name is: "<< myAccount.getname();

    cout<<"\nPlease enter account name: ";
    string theName;
    getline(cin,theName);
    myAccount.setName()


}