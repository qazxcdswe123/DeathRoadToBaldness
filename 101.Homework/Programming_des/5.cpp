#include <iostream>
#include <cstring>

using namespace std;

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_string(const char *string_array[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << string_array[i] << endl;
    }
}

// Q1
// 用指针和引用两种方法作为函数的参数实现：输入3个整数，按由小到大的顺序输出。
void print_using_pointer(int *a, int *b, int *c) // 用指针作为参数
{
    if (*a > *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c)
    {
        int temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c)
    {
        int temp = *b;
        *b = *c;
        *c = temp;
    }
    cout << *a << " " << *b << " " << *c << " 用指针作为参数" << endl;
}

// Q1
void print_using_reference(int &a, int &b, int &c) // 用引用作为参数
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (a > c)
    {
        int temp = a;
        a = c;
        c = temp;
    }
    if (b > c)
    {
        int temp = b;
        b = c;
        c = temp;
    }
    cout << a << " " << b << " " << c << " 用引用作为参数" << endl;
}

// 用指针操作数组实现：有n个人围成一圈，顺序排号。从第1个人开始报数（从1~3报数），
// 凡报到3的人退出圈子，问最后留下的人原来排在第几号。
// 用链表会方便很多
// Q2
int array_using_pointer(int array[], int length) // 1 is out ; 0 is in, initialize the array with 0
{
    int index = 0, count = 1;
    int remain = length;
    while (remain != 1)
    {
        if (index >= length) // loop through the circle
        {
            index = 0;
        }

        if (*(array + index) == 0 && count % 3 != 0) // continue the circle
        {
            index++;
            count++;
        }
        else if (*(array + index) == 0 && count % 3 == 0) // leave the circle
        {
            *(array + index) = 1;
            index++;
            count = 1;
            remain--;
        }
        else
        {
            index++;
        }
    }

    print_array(array, length);

    for (index = 0; index < length; index++) // find the index
    {
        if (*(array + index) == 0)
        {
            break;
        }
    }

    return index;
}

// 在一个具有n个元素的整型数组p中查找一个整数m，如果在数组中找到该数，则将该数置为0；
// 否则数据不变。（用指针作为函数参数的方法实现）
// Q3
void find_and_set_zero_using_pointer(int *array1, int length1, int target)
{
    for (int i = 0; i < length1; i++)
    {
        if (*(array1 + i) == target)
        {
            *(array1 + i) = 0;
            break;
        }
    }
}

// 在主函数中输入10个字符串。用另一函数对它们排序，
// 然后在主函数输出这10个已排好序的字符串。（用指针数组的方法实现）
// Q4
void sort_string_array_using_pointer(const char *array1[], int length1)
{
    for (int i = 0; i < length1; i++)
    {
        for (int j = 0; j < length1 - i - 1; j++)
        {
            if (strcmp(*(array1 + j), *(array1 + j + 1)) > 0)
            {
                const char *temp = *(array1 + j);
                *(array1 + j) = *(array1 + j + 1);
                *(array1 + j + 1) = temp;
            }
        }
    }
}

int main(void)
{
    cout << "Question1" << endl;
    int a, b, c;
    cout << "Please input three integers:" << endl;
    cin >> a >> b >> c;
    print_using_pointer(&a, &b, &c);
    cout << "Please input three integers again:" << endl; // 上个函数用指针操作已经改变了 abc
    cin >> a >> b >> c;
    print_using_reference(a, b, c);

    cout << "------------------" << endl;
    cout << "Question2" << endl;
    int array[5] = {0};
    int length = sizeof(array) / sizeof(array[0]);
    int index = array_using_pointer(array, length);
    cout << "The index is " << index + 1 << endl;

    cout << "------------------" << endl;
    cout << "Question3" << endl;
    int array1[5] = {9, 1, 3, 5, 6};
    int length1 = sizeof(array1) / sizeof(array1[0]);
    cout << "Before: ";
    print_array(array1, length1);
    find_and_set_zero_using_pointer(array1, length1, 3);
    cout << "After: ";
    print_array(array1, length1);

    cout << "------------------" << endl;
    cout << "Question4" << endl;
    // ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
    // ISO 禁止把字符串常量转换为'char*' 应用 const char* 代替
    const char *str[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    int length2 = sizeof(str) / sizeof(str[0]);
    cout << "Before: ";
    print_string(str, length2);
    sort_string_array_using_pointer(str, length2);
    cout << endl
         << "After: ";
    print_string(str, length2);
}