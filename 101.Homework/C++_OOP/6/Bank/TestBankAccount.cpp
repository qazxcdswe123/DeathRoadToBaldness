#include "BankAccount.h"
#include <iostream>

int main()
{
    OneYearAccount one(100);
    std::cout << "Balance: " << one.getBalance() << std::endl;
    std::cout << "One Year Interest: " << one.getTotalInterest() << std::endl;

    TwoYearAccount two(200);
    std::cout << "Balance: " << two.getBalance() << std::endl;
    std::cout << "Two Year Interest: " << two.getTotalInterest() << std::endl;

    ThreeYearAccount three(300);
    std::cout << "Balance: " << three.getBalance() << std::endl;
    std::cout << "Three Year Interest: " << three.getTotalInterest() << std::endl;

    FiveYearAccount five(500);
    std::cout << "Balance: " << five.getBalance() << std::endl;
    std::cout << "Five Year Interest: " << five.getTotalInterest() << std::endl;

    BankAccount *array[4] = {&one, &two, &three, &five};
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Interest is " << array[i]->getTotalInterest() << std::endl;
    }
}