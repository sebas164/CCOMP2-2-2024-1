#include<iostream>
using namespace std;

int main(){
    int num;
    int n1=0,n2=1,n3=0;
    cin>>num;

    for(int i=0;i<num;i++){
        n3=n1+n2;
        n1=n2;
        n2=n3;
    }

    cout<<n3;




    return 0;
}