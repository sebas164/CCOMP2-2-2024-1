#include <iostream>
#include <string>
using namespace std;
class Account{
    private:
        string name;
        int balance=0;
    
    public:
        Account(string accountName, int initialBalance ){
            name=accountName;
        }

        if(initialBalance>0){
            balance=initialBalance;
        }
        void withdraw(int wirhdrawAmount){
            if(wirhdrawAmount>balance){
                cout<<"El monto excedio su saldo"<<endl;
            }else{
                balance=balance-wirhdrawAmount;
                cout<<balance<<endl;

            }
        }
        void deposit(int depositAmount) {
            if (depositAmount > 0) { // if the depositAmount is valid
                balance = balance + depositAmount; // add it to the balance
            }
        }
        int getBalance() const {
            return balance;
        }
        void setName(string accountName) {
             name = accountName;
        }

        std::string getName() const {
            return name;
        }
};
class Date{
    private:
        int month=1;
        int day;
        int year;
    public:
        Date(int month_, int day_, int year_){
            if(month_<13 && month_>0){
                month=month_;
            }            
            day=day_;
            year=year_;
        }
        int getMonth(){
            return month;
        }

        void setMonth(int reMonth){
            month=reMonth;
        }

        int getDay(){
            return day;
        }
        void setDay(int reDay){
            day=reDay;
        }

        int getYear(){
            return year;
        }
        void setYear(int reYear){
            year=reYear;
        }
        
        void displayDate(){
            cout<<month<<"/"<<day<<"/"<<year<<endl;
        }


};

int main()
{
    

    return 0;
}