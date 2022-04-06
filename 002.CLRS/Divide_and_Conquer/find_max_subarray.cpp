// find maxium subarray implementation from clrs book

#include <iostream>
#include <climits>

using namespace std;

class array
{
public:
    int left;
    int right;
    int sum;

    array(int l, int r, int s)
    {
        left = l;
        right = r;
        sum = s;
    }
};

array *Find_max_crossing_subarray(int arr[], int low, int mid, int high)
{
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    int max_right = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }

    return new array(max_left, max_right, left_sum + right_sum);
}

array *Find_Max_Subarray(int arr[], int low, int high)
{
    if (low == high)
    {
        return new array(low, high, arr[low]);
    }
    else
    {
        int mid = (low + high) / 2;
        array *left_subarray = Find_Max_Subarray(arr, low, mid);
        array *right_subarray = Find_Max_Subarray(arr, mid + 1, high);
        array *cross_subarray = Find_max_crossing_subarray(arr, low, mid, high);

        if (left_subarray->sum >= right_subarray->sum && left_subarray->sum >= cross_subarray->sum)
        {
            return left_subarray;
        }
        else if (right_subarray->sum >= left_subarray->sum && right_subarray->sum >= cross_subarray->sum)
        {
            return right_subarray;
        }
        else
        {
            return cross_subarray;
        }
    }
}

int max_subarray_using_dp(int arr[], int length)
{
    int sum = 0;
    int max_sum = 0;
    int currentHigh = 0;
    int high = 0;
    int currentLow = 0;
    int low = 0;

    for (int i = 0; i < length; i++)
    {
        currentHigh = i;
        if (sum > 0)
        {
            sum += arr[i];
        }
        else
        {
            currentLow
        }
        
        
    }
    
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    array *max_subarray = Find_Max_Subarray(arr, 0, n - 1);
    cout << "max subarray: " << max_subarray->left << "-" << max_subarray->right << " sum:" << max_subarray->sum << endl;
    return 0;
}