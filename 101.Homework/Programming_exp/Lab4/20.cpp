/*18) 编写一个函数, 在一个数组中查找出其值等于给定值x的所有元素,函数的返回值是数组中其值等于给定值的元素的个数。*/

#include <iostream>
using namespace std;

int find_x(int target, int array[], int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (array[i] == target)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 5, 5, 5};
    int target = 5;
    int length = sizeof(array) / sizeof(array[0]);
    int count = find_x(target, array, length);
    cout << "The number of " << target << " is " << count << endl;
    return 0;
}