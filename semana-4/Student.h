#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
        string name;
        int age;
    public:
        explicit Student(string n,int a){
            name=n;
            age=a;
        }

        string getName(){
            return name;
        }

        void setName(string nombre){
            name=nombre;
        }

        int getAge(){
            return age;
        }

        void setAge(int edad){
            age=edad;
        }

        bool isOlder() const{
            if(age>=18){
                return true;
            }
            else{
                return false;
            }
        }
};