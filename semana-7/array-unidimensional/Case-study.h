#include <array>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class GradeBook {

    public:

        static const size_t students{15}; 

        GradeBook(const string &name, const array<int, students> &gradesArray) {
            courseName = name;
            grades = gradesArray;
        }

        void setCouseName(const string &name){
            courseName=name;
        }

        const string& getCourseName() const{
            return courseName;
        }

        void displayMessage() const{
            cout<<"Welcome to the grade book for\n" <<getCourseName()<<endl;
        }
        void processGrades() const {
            outputGrades();
            // call function getAverage to calculate the average grade
            cout << std::setprecision(2) << std::fixed;
            cout << "\nClass average is " << getAverage() <<endl;

            cout << "Lowest grade is " << getMinimum()<< "\nHighest grade is " << getMaximum() << std::endl;

            outputBarChart(); 
        }

        int getMinimum() const {
            int lowGrade{100}; // assume lowest grade is 100


            for (int grade : grades) {

                if (grade < lowGrade) {
                    lowGrade = grade; // new lowest grade
                }
            }

            return lowGrade; // return lowest grade
        }


        int getMaximum() const {
            int highGrade{0}; // assume highest grade is 0


            for (int grade : grades) {

                if (grade > highGrade) {
                highGrade = grade; // new highest grade
                }
            }

            return highGrade; // return highest grade
        }


        double getAverage() const {
            int total{0}; // initialize total

            // sum grades in array
            for (int grade : grades) {
                total += grade;
            }


            return static_cast<double>(total) / grades.size();
        }
        void outputBarChart() const {
            cout << "\nGrade distribution:" << std::endl;

            // stores frequency of grades in each range of 10 grades
            const size_t frequencySize{11};
                array<unsigned int, frequencySize> frequency{};
                for (int grade : grades) {
                    ++frequency[grade / 10];
                }

                
            for (size_t count{0}; count < frequencySize;    ++count) {           
                if (0 == count) {
                    cout << " 0-9: ";
                }
                else if (10 == count) {
                    cout << " 100: ";
                }
                else {
                    cout << count * 10 << "-" << (count * 10) + 9<< ": ";
                }
                
                // print bar of asterisks
                for (unsigned int stars{0}; stars < frequency[count]; ++stars) {
                    cout << '*';
                }

                cout << std::endl; // start a new line of output
            }
        } 

        void outputGrades() const {
            cout << "\nThe grades are:\n\n";

            for (size_t student{0}; student < grades.size(); ++student) {
                cout << "Student " << std::setw(2) << student + 1 << ": "<<setw(3) << grades[student] << std::endl;
            }
        }
    private:
        string courseName;        
        array<int,students> grades;
        
};
