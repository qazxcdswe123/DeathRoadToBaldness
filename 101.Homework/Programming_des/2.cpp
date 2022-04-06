#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// Easy condition
void function1()
{
    int x;
    cout << "---Function---\n"
         << "Plz gime your X: ";
    cin >> x;
    if (x < 1)
    {
        cout << "Y = " << x << endl;
    }
    else if (x >= 1 && x < 10)
    {
        cout << "Y = " << 2 * x - 1 << endl;
    }
    else
    {
        cout << "Y = " << 3 * x - 11 << endl;
    }
}

// Easy condition
void printGrade()
{
    int grade;
    cout << "---printGrade---\n"
         << "Plz gime your Grade: ";
    cin >> grade;
    if (grade >= 90)
    {
        cout << "Grade A" << endl;
    }
    else if (grade >= 80 && grade < 90)
    {
        cout << "Grade B" << endl;
    }
    else if (grade >= 70 && grade < 80)
    {
        cout << "Grade C" << endl;
    }
    else if (grade >= 60 && grade < 70)
    {
        cout << "Grade D" << endl;
    }
    else
    {
        cout << "Grade E" << endl;
    }
}

// int overflow & the design of the function
void factorial()
{
    cout << "---factorial---\n";
    unsigned long long ans = 1;
    unsigned long long temp = 1;
    for (int i = 2; i <= 20; i++)
    {
        temp *= i;
        ans += temp;
    }
    cout << ans << "\n";
}

// simply get each digit
void sxhNumber()
{
    cout << "---shui_xian_hua---\n";
    int num1, num2, num3;
    for (int i = 100; i < 1000; i++)
    {
        num3 = i % 10;
        num2 = (i / 10) % 10;
        num1 = i / 100;
        if (pow(num3, 3) + pow(num2, 3) + pow(num1, 3) == i)
        {
            cout << i << " is a sxhNumber :D\n";
        }
    }
}

/* I tried to use linked lists at first
but it makes the function really complicated
so I switched back to vector :D
vector in this case is really convenient

I used a trick to reduce the calculation times
by using j * j <= i, we can calculate less
*/

void perfectNumber()
{
    int upperBound = 1000;
    cout << "---perfectNumber---\n";
    cout << "1,its factor is 1\n";

    for (int i = 2; i < upperBound; i++)
    {
        vector<int> factors{1};
        for (int j = 2; j * j <= i; j++)
        {
            if (j * j == i)
            {
                factors.push_back(j);
            }
            else if (i % j == 0)
            {
                factors.push_back(j);
                factors.push_back(i / j);
            }
        }

        int size = factors.size();
        int sum = 0;
        if (size > 1)
        {
            for (int i = 0; i < size; i++)
            {
                sum += factors[i];
            }
            if (sum == i)
            {
                cout << i << ",its factors are ";
                sort(factors.begin(), factors.end());
                for (int i = 0; i < size - 1; i++)
                {
                    cout << factors[i] << ", ";
                }
                cout << factors[size - 1] << "\n";
            }
        }
    }
}

/*
想使用模拟的方法做, 能输出分数，结果overflow，懒得用字符串搞大数算法了，还是正常点吧
在10几时候overflow，麻烦

int gcd_recursive(unsigned long long a, unsigned long long b)
{
    if (b)
        return gcd_recursive(b, a % b);
    else
        return a;
}

void sequence()
{
    double up = 2, down = 1;
    int temp;
    int uparr[20];
    int downarr[20];

    // store data
    for (int i = 0; i < 20; i++)
    {
        uparr[i] = up;
        downarr[i] = down;
        temp = up;
        up += down;
        down = temp;
    }

    // calculate in fraction
    up = 2, down = 1;
    int gcd;
    for (int i = 1; i < 20; i++)
    {
        up = up * downarr[i] + uparr[i] * down;
        down *= downarr[i];
        gcd = gcd_recursive(up, down);
        up /= gcd;
        down /= gcd;
    }

    cout << "the answer is " << up << " / " << down << endl;
}
*/

// ez
void sequence()
{
    cout << "---sequence---" << endl;
    int i, t, n = 20;
    double a = 2, b = 1, s = 0;
    for (i = 1; i <= n; i++)
    {
        s = s + a / b;
        t = a;
        a = a + b;
        b = t;
    }
    cout << "sum = " << s << endl;
}

int main(void)
{
    function1();
    printGrade();
    factorial();
    sxhNumber();
    perfectNumber();
    sequence();
}