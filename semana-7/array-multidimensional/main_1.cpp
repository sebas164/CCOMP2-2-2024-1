
#include<array>
#include "GradeBook.h"

using namespace std;

int main(){
    array<array<int, GradeBook::tests>,GradeBook::students>grades{1,2,3,40,50,6,7,8,9,10,11,12,20,21,22,10,11,12,80,43,100,10,100,12,10,70,12,90,11,12};
    
    GradeBook myGradeBook("Ciencia de la computacion I",grades);
    myGradeBook.displayMessage();
    myGradeBook.processGrades();    


    return 0;
}

