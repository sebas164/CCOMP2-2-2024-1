#include<string>
#include <array>
#include<iostream>
#include "Case-study.h"
using namespace std;

int main(){
    const array<int, GradeBook::students> grades{
        1,2,30,4,54,6,7,8,59,100};
        string courseName{"ciencia de la computacion I"};
    

    GradeBook myGradebook(courseName,grades);
    myGradebook.displayMessage();
    myGradebook.processGrades();
    myGradebook.outputGrades();


   
}



