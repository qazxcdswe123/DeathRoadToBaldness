/*19) 定义函数Max_Array 求一维数组中的最大元素值。尽可能设计不同形式参数的函数原型，并定义它们的实现。用main函数进行测试，比较不同参数的定义和使用形式。*/
#include <iostream>
using namespace std;

int Max_Array(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    cout << Max_Array(array, n) << endl;
    return 0;
}