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
            else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
                if(d>=1 && d<=31){
                day=d;

                }
            }
            else if(m==4 || m==6 || m==8 || m==9 || m==11){
                if(d>=1 && d<=30){
                day=d;

                }
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
        else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
            if(d>=1 && d<=31){
                day=d;

            }
        }
        else if(month==4 || month==6 || month==8 || month==9 || month==11){
            if(d>=1 && d<=30){
                day=d;

            }
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
