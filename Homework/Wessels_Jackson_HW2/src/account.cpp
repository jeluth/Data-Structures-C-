#include "account.h"
namespace main_wessels_2
{

account::account(double initialBalance, double initialInterestRate)
{
    balance = initialBalance;
    interest = initialInterestRate;
}

void account::setBalance(double newBalance)
{
    balance = newBalance;
}

void account::setInterestRate(double newRate)
{
    interest = newRate;
}

void account::withdraw(double amount)
{
   balance -= amount;
}

void account::deposit(double amount)
{
    balance += amount;
}

void account::addInterest(double years)
{
    balance += (years * interest);
}

}
