#include "BankAccount.h"

BankAccount::BankAccount(double b) : balance(b){};

void BankAccount::setBalance(double b)
{
    this->balance = b;
}

OneYearAccount::OneYearAccount(double b)
{
    BankAccount::setBalance(b);
}

TwoYearAccount::TwoYearAccount(double b)
{
    BankAccount::setBalance(b);
}

ThreeYearAccount::ThreeYearAccount(double b)
{
    BankAccount::setBalance(b);
}

FiveYearAccount::FiveYearAccount(double b)
{
    BankAccount::setBalance(b);
}

double OneYearAccount::interest = 0.1;
double TwoYearAccount::interest = 0.2;
double ThreeYearAccount::interest = 0.3;
double FiveYearAccount::interest = 0.5;

double BankAccount::getBalance() const { return balance; }

double OneYearAccount::getTotalInterest() const
{
    return getBalance() * interest;
}

double TwoYearAccount::getTotalInterest() const
{
    return getBalance() * interest;
}

double ThreeYearAccount::getTotalInterest() const
{
    return getBalance() * interest;
}

double FiveYearAccount::getTotalInterest() const
{
    return getBalance() * interest;
}