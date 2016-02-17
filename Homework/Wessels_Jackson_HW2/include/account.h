#ifndef ACCOUNT_H
#define ACCOUNT_H
//FILE:point.h
//CLASS PROVIDED: account - allows user to manage bank account and interest rate.
//
//CONSTRUCTOR for the account class:
//    account(double intialBalance = 0.0, double intialInterestRate = 0.0)
//        Postcondition: creates an account set to the initialBalance and initialInterestRate.
//
//MODIFICATION MEMBER FUNCTIONS for the account class:
//    void setBalance(double newBalance)
//        Postcondition: sets the balance to newBalance.
//
//    void setInterestRate(double newRate)
//        Postcondition: sets the interest rate to newRate.
//
//    void withdraw(double amount)
//        Postcondition: subtracts amount from balance.
//
//    void deposit(double amount)
//        Postcondition: adds amount to balance.
//
//    void addInterest(double years)
//        Postcondition: adds interest to account based on years entered.
//
//CONSTANT MEMBER FUNCTIONS for the account class:
//    double getBalance() const
//        Postcondition: returns the balance,
//    double getInterestRate() const
//        Postcondition: returns the interest.
using namespace std;
namespace main_wessels_2
{

class account
{
    public:
        //CONSTRUCTOR
        account(double initialBalance = 0.0, double initialInterestRate = 0.0);
        //MODIFICATION MEMBER FUNCTIONS
        void setBalance(double newBalance);
        void setInterestRate(double newRate);
        void withdraw(double amount);
        void deposit(double amount);
        void addInterest(double years);
        //CONSTANT MEMBER FUNCTIONS
        double getBalance() const {return balance;}
        double getInterestRate() const {return interest;}
    protected:
    private:
        double balance, interest;
};
}
#endif // ACCOUNT_H
