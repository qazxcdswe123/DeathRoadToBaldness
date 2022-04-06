#include <iostream>

using namespace std;

int main(void)
{
    double applePrice = 2.5, pearPrice = 1.8, bananaPrice = 2.0, orangePrice = 1.6;
    double paid, change;
    double apple, pear, banana, orange;
    cout << "Apple weight: ";
    cin >> apple;
    cout << "Pear weight: ";
    cin >> pear;
    cout << "Banana weight: ";
    cin >> banana;
    cout << "Orange weight: ";
    cin >> orange;

    double sum = apple * applePrice + banana * bananaPrice + pear * pearPrice + orange * orangePrice;
    cout << "You have paid: ";
    cin >> paid;
    change = paid - sum;
    cout << "The change is: " << change << '\n';
}
