#include <iostream>
using namespace std;

int main(void)
{
    double grade;
    int count, count_ex, count_good, count_pass, count_no_pass;
    count = 1;
    count_ex = count_good = count_pass = count_no_pass = 0;
    while (count <= 30)
    {
        cout << "请输入第 " << count << " 名学生的成绩：";
        cin >> grade;
        while (grade < 0 || grade > 100)
        {
            cout << "数据错误！请重新输入第 " << count << " 个学生的成绩：";
            cin >> grade;
        }
        if (grade >= 90)
            count_ex++;
        else if (grade >= 75)
            count_good++;
        else if (grade >= 60)
            count_pass++;
        else
            count_no_pass++;
        count++;
    }
    cout << "优秀人数：" << count_ex << " 人\n";
    cout << "良好人数：" << count_good << " 人\n";
    cout << "合格人数：" << count_pass << " 人\n";
    cout << "不合格人数：" << count_no_pass << " 人\n";
}
