#include <iostream>
using namespace std;

int main()
{
    double apple, ans, paid, change;
    cout << "Apple weight: ";
    cin >> apple;
    cout << "Money paid: ";
    cin >> paid;
    if (apple < 4)
        ans = apple * 1.8;
    else
    {
        if (apple < 6)
            ans = apple * 1.5;
        else
        {
            if (apple < 8)
                ans = apple * 1.2;
            else
            {
                if (apple < 10)
                    ans = apple * 1;
                else
                    ans = apple * 0.8;
            }
        }
    }
    change = paid - ans;
    printf("You should pay: %.2lf\nYou should pay back: %.2lf", ans, change);
}