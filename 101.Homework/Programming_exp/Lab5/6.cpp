// 5) 一直某个学习小组三门课程的成绩如下：
//  	英    语	高 等 数 学	C++程序设计
// 学生1	85	90	80
// 学生2	65	70	75
// 学生3	75	85	77
// 使用二维数组存放该学习小组三门课程的成绩，计算每个学生的平均成绩和该小组每门课程的平均成绩。
#include <iostream>
using namespace std;

int main()
{
    int array[3][3] = {
        {85, 90, 80},
        {65, 70, 75},
        {75, 85, 77}};

    int averageScore[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            averageScore[i] += array[i][j];
        }
        averageScore[i] /= 3;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "学生" << i + 1 << "的平均成绩为：" << averageScore[i] << endl;
    }

    int averageGroup[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            averageGroup[i] += array[j][i];
        }
        averageGroup[i] /= 3;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "课程" << i + 1 << "的平均成绩为：" << averageGroup[i] << endl;
    }
}