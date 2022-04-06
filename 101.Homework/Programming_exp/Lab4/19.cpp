/*17) 编写一个函数,在一个数组中查找出其值等于给定值x的第一个元素,如果查找成功, 返回这个元素的下标, 否则返回-1。*/
#include <iostream>
using namespace std;

int find(int array[], int length, int target)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(array) / sizeof(array[0]);
    int target = 5;
    int index = find(array, length, target);
    if (index == -1)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found at index " << index << endl;
    }
    return 0;
}