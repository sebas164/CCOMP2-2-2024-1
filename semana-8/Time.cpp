#include <iostream>
using namespace std;


class Time{
    private:
        unsigned int hour=0;
        unsigned int minute=0;
        unsigned int second=0;
    public:

        void setTime(int h, int m, int s){
            if((h>=0 && h<24) && (m>=0 && m<60) && (s>=0 && s<60)){
                hour=h;
                minute=m;
                second=s;

            }
            else{
                throw invalid_argument(                       "hour, minute and/or second was out of range");
            }
        }  

        unsigned int getHour() const{
            return hour;
        } 

        unsigned int& badSetHour(int hh){
            if(hh>=0 && hh<24){
                hour=hh;
            }
            else {
                throw invalid_argument("hour must be 0-23");
            }

            return hour;
        } 
};


int main(){

    Time t;
    t.badSetHour(23)=8;
    cout<<t.getHour()<<endl;
    t.badSetHour(12)=74;
    cout<<"la hora es:"<<endl;
    cout<<t.getHour();

  return 0;
}