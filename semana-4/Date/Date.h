#include <iostream>
#include <string>
using namespace std;

class Date {
 private:
    int day=1;
    int year=1900;
    int month=1;
public:
    explicit Date(int d, int m, int y) {
        if(m >= 1 && m <= 12) {
        month = m;
        }
        if(y>=1900 && y<=2050){
            year=y;
        }
        if(d>=1 && d<=31){
            if(m==2 && ((y%4==0 && y%100!=0) || y%400==0)){
                if(d>=1 && d<=29){
                    day=d;
                }
                
            }
            else if(m==2 && d>=1 && d<=28){
                day=d;
            }
            else if(m!=2){
                day=d;
            }
        }

    }
    void setDay(int d) {
        if(month==2 && ((year%4==0 && year%100!=0) || year%400==0)){
            if(d>=1 && d<=29){
                day=d;
            }
        }
        else if(month==2 && d>=1 && d<=28){
                day=d;
        }
        else{
            day=d;
        }
       
    }
    void setMonth(int m) {
        if(m >= 1 && m <= 12) {
            month = m;
        }
    }
    void setYear(int y) {
        if(y>=1900 && y<=2050){
            year=y;
        }
    }
    int getDay() const {
        return day;
    }
    int getMonth() const {
        return month;
    }
    int getYear() const {
        return year;
    }
    void displayDate() const {
        cout << day << " / " << month << " / " << year <<endl;
    }

    bool isLeapYear() const{
        if((year%4==0 && year%100!=0) || year%400==0){
            return true;
        }
        else{
            return false;
        }
    }
 };