/*20) 排序是为了快速查找。定义一个函数，在有序数组中查找指定值，想一想怎样才能找的更快。*/
#include <iostream>
using namespace std;

int randomArray(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % 10;
    }
    return 0;
}

int quickFind(int array[], int target, int length)
{
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (array[mid] == target)
        {
            return mid;
        }
        else if (array[mid] > target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

void PrintArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[5] = {0};
    int length = sizeof(array) / sizeof(array[0]);
    int target = 5;
    randomArray(array, length);
    PrintArray(array, length);

    int index = quickFind(array, target, length);
    if (index != -1)
    {
        cout << "Found " << target << " at " << index << endl;
    }
    else
    {
        cout << "Didnt find " << target << endl;
    }
}