#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

using namespace std;

void outputVector( const vector<int>&);
void inputVector(vector<int>& );
int main(){
    vector<int>integral1(7);
    vector<int>integral2(10);

    cout<<"Tamaño del vector integral1 es: "<<integral1.size()<<"\nVector despues de la inizializacion";
    outputVector(integral1);

    
    cout << "\nTamaño del vector integral2 es " <<integral2.size() << "\nvector despues inizializacion:";
    outputVector(integral2);

    
    cout << "\nIngresa 17 enteros:" << endl;
    inputVector(integral1);
    inputVector(integral2);

    cout << "\nAfter input, the vectors contain:\n" << "integers1:";
    outputVector(integral1);
    cout << "integers2:";
    outputVector(integral2);
 
    cout << "\nEvaluating: integers1 != integers2" << endl;

    if (integral1 != integral2) {
        cout << "integers1 and integers2 are not equal" << endl;
    }

    vector<int> integral3{integral1};

    cout << "\nTamaño del vector integral3 is " <<integral3.size() << "\nvector after initialization: ";
    outputVector(integral3);

    cout<<"\nAsignar integral2 a integral1"<<endl;
    integral1=integral2;

    cout << "integral1: ";
    outputVector(integral1);
    cout << "integral2: ";
    outputVector(integral2);

    cout<<"\n Evaluando integral1==integral2"<<endl;

    if(integral1==integral2){
        cout<<"Integral1 and integral2 son iguales"<<endl;
    }

    cout << "\nintegral1[5] es " << integral1[5];
    cout << "\n\nAssigning 1000 to integral1[5]" << endl;
    integral1[5] = 200;
    cout << "integral1: ";
    outputVector(integral1);
    try {
        cout << "\nAttempt to display integral1.at(15)" << endl;
        cout << integral1.at(15) << endl;
    }
    catch (out_of_range &ex) {
        cerr << "An exception occurred: " << ex.what() << endl;
    } 

    cout << "\nCurrent integers3 size is: " << integral3.size() << endl;
     integral3.push_back(1000); 
     cout << "New integers3 size is: " << integral3.size() << endl;
     cout << "integers3 now contains: ";
     outputVector(integral3);




} 
    void outputVector(const vector<int> &items ) {
        for (int item : items) {
            cout << item << " ";
        }

        cout << endl;
    }
    void inputVector(vector<int> &items ) {
        for (int& item : items) {
            cin >> item;
        }
    }
    