#include <iostream>
using namespace std;

class CreateAndDestroy{
    private:
        int objectID;
        string message;

    public:
        CreateAndDestroy(int ID,string messageString){
            objectID=ID;
            message=messageString;
            cout<<"ObjectID "<<objectID<<"  constructor run "<<message<<endl;
        }    

        ~CreateAndDestroy(){
            if(objectID==1 || objectID==6){
                cout<<"\n";
            }else{
                cout<<"";
            }

            cout<<"Object "<<objectID<<"  destructor runs "<<message<<endl;
        }

};

void create(){
    cout<<"\nCREATE FUNCTION; EXECUTION BEGINS"<<endl;
    CreateAndDestroy fifth(5,"local in create");
    static CreateAndDestroy sixth(6,"local static in create");
    CreateAndDestroy seventh(7,"local in create");
    cout<<"\nCREATE FUNCTION: EXECUTION ENDS "<<endl;
}

CreateAndDestroy first(1,"global before main");
int main(){
    cout<<"\nMAIN FUNCTION: EXECUTION BEGINS"<<endl;
    CreateAndDestroy second(2,"local in main");
    static CreateAndDestroy third(3,"local static in main");

    create();

    cout<<"\nMAIN FUNCTION: EXECUTION RESUMES"<<endl;
    CreateAndDestroy fourth(4,"local in main");
    cout<<"\nMAIN FUNCTION: EXECUTION ENDS"<<endl;




}