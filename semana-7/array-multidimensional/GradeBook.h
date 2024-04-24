#include <array>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

 class GradeBook {


    public:
        static const size_t students{10};
        static const size_t tests{3};

        

        GradeBook(const string &name,array<array<int, tests>, students> &gradesArray){
            courseName=name;
            grades=gradesArray; 

        }


        void setCourseName(const string &name) {
             courseName = name;
        }


        const string& getCourseName() const {
            return courseName;
        }

        void displayMessage() const {

            cout<< "Welcome to the grade book for\n" << getCourseName()<< "!" << std::endl;
        }

        void processGrades() const {
            outputGrades(); 
 
            cout << "\nLowest grade in the grade book is " << getMinimum()<< "\nHighest grade in the grade book is " << getMaximum()<< std::endl;

            outputBarChart();
        }

        int getMinimum() const {
            int lowGrade{100};
            for(auto const &student : grades){
                for(auto const &grade:student){
                    if(grade<lowGrade){
                        lowGrade=grade;
                    }

                }
            }

            return lowGrade;
        }

        int getMaximum() const {
            int highGrade{0};

            
            for (auto const& student : grades) {
 
                for (auto const& grade : student) {
                    if (grade > highGrade) { 
                        highGrade = grade;
                    }
                }
            }

            return highGrade; 
        }

 
        double getAverage(const std::array<int, tests>&setOfGrades) const {
            int total{0}; 
            for (int grade : setOfGrades) {
                  total += grade;
            }

 
            return static_cast<double>(total) / setOfGrades.size();
        }

        void outputBarChart() const {
            cout << "\nOverall grade distribution:" << endl; 
            const size_t frequencySize{11};
            array<unsigned int, frequencySize> frequency{}; 
            for (auto const& student : grades) {
                for (auto const& test : student) {
                    ++frequency[test / 10];
                }
            }

 
            for (size_t count{0}; count < frequencySize; ++count) {
 
                if (0 == count) {
                    cout << " 0-9: ";
                }
                else if (10 == count) {
                    cout << " 100: ";
                }
                else {
                    cout << count * 10 << "-" << (count * 10) + 9 << ": ";
                }


                for (unsigned int stars{0}; stars < frequency[count]; ++stars){
                    cout << '*';
                }
                cout << endl;
            }
        }    

 
        void outputGrades() const {
            cout << "\nThe grades are:\n\n";
            cout << "             "; 
            for (size_t test{0}; test < tests; ++test) {
                cout << "Test " << test + 1 << " ";
            }

            cout << "Average" << std::endl;


            for (size_t student{0}; student < grades.size(); ++student) {
                cout << "Student " << std::setw(2) << student + 1;
                    for (size_t test{0}; test < grades[student].size(); ++test) {
                            cout << std::setw(8) << grades[student][test];
                    }


                double average{getAverage(grades[student]) };
                cout << std::setw(9) << std::setprecision(2) << std::fixed<< average << std::endl;
            }
         } 



    private:
        string courseName;
        array<array<int,tests>, students>grades;

 };        