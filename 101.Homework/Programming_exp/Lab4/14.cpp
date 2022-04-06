// 让学生自己输入两个加数，通过这两个加数给学生出一道加法运算题，如果学生输入答案正确，则显示“Right！”否则显示“Not correct! Try again!”，程序结束。
#include <iostream>
using namespace std;

void function1(int a, int b, int c)
{
    if (c == (a + b))
    {
        cout << "Right!" << endl;
    }
    else
    {
        cout << "Not correct! Try again!" << endl;
    }
}

// 让学生自己输入两个加数，通过这两个加数给学生出一道加法运算题，如果学生输入答案正确，则显示“Right！”否则显示“Not correct! Try again!”，直到做对为止。
void function2()
{
    int a, b, c;
    while (1)
    {
        cout << "Please input two numbers: " << endl;
        cin >> a >> b;
        cout << "Please input the answer: " << endl;
        cin >> c;
        function1(a, b, c);
    }
}

// 让学生自己输入两个加数，通过这两个加数给学生出一道加法运算题，如果学生输入答案正确，则显 示“Right！”否则提示重做，显示“Not correct! Try again!”，重做机会最多给三次，如果三次仍未做对，则显示“Not correctm,You have tried three times! Test over!”，程序结束。
void function3()
{
    int a, b, c;
    int count = 0;
    while (1)
    {
        cout << "Please input two numbers: " << endl;
        cin >> a >> b;
        cout << "Please input the answer: " << endl;
        cin >> c;
        function1(a, b, c);
        count++;
        if (count == 3)
        {
            cout << "Not correctm,You have tried three times! Test over!" << endl;
            break;
        }
    }
}

// 将程序设计成连续做十道题，让学生自己输入两个加数，通过这两个加数给学生出一道加法运算题，如果学生输入答案正确，则显示“Right！”否则显示“Not correct！”，不给机会重做，十道题做完后，按每题10分统计总得分，然后打印出总分和做错的题数
void function4()
{
    int a, b, c, i = 0, score = 0, wrong = 0;
    while (i < 10)
    {
        cout << "Please input two numbers: " << endl;
        cin >> a >> b;
        cout << "Please input the answer: " << endl;
        cin >> c;
        function1(a, b, c);
        i++;
        if (c != (a + b))
        {
            wrong++;
        }
        else
        {
            score += 10;
        }
    }
    cout << "Your score is " << score << " and you have " << wrong << " wrong." << endl;
}

int main()
{
    int a = 1, b = 2, c = 3;
    function1(a, b, c);
    function2();
    function3();
    function4();
}