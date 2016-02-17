#include <iostream>
#include <cstdlib>
#include "point.h"
#include "account.h"
#include "complexNumb.h"

using namespace std;
using main_wessels_1::point;
using main_wessels_2::account;
using main_wessels_3::complexNumb;


int main()
{
    point myPoint(1.0, 1.0, 1.0);
    myPoint.shift(1.5, 2.5, 2.0);
    cout << myPoint << endl;
    myPoint.rotate("x",90.0);
    cout << myPoint << endl;

    double userBalance, userInterest;
    cout << "Enter your balance: $";
    cin >> userBalance;
    cout << "Enter your interest rate: ";
    cin >> userInterest;

    account myAccount(userBalance, userInterest);

    double userDeposits;
    cout << "Enter any annual deposits: $";
    cin >> userDeposits;

    double desiredBalance;
    cout << "Enter your desired balance: $";
    cin >> desiredBalance;

    int years = 0;
    while (desiredBalance - myAccount.getBalance() > 0)
    {
        myAccount.deposit(userDeposits);
        double balance = myAccount.getBalance() + (myAccount.getBalance() * myAccount.getInterestRate());
        myAccount.setBalance(balance);
        years++;
    }

    cout << "It will take " << years << " years to reach your desired balance." << endl;

    complexNumb numb1(20.5, 10.5);
    complexNumb numb2(20.0, 10.0);

    complexNumb complexSum = numb1 + numb2;


    cout << complexSum.getReal() << " +/- " << complexSum.getImaginary() << "i" << endl;





    return 0;
}
