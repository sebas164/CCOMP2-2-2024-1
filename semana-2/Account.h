#include <string>

class Account{

    public:
        void setName(std::string accountName){
            name=accountName;
        }
    private:
}

        void setName(std::string accountName) {
10      name = accountName; // store the account name
11      }
12
13 /    / member function that retrieves the account name from the object
14      std::string getName() const {
15          return name; // return name's value to this function's caller
16      }
17      private:
18     std::string name; // data member containing account holder's name
19     }; // end class Account