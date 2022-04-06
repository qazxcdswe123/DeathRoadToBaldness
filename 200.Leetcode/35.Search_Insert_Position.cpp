class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int num = nums[mid];
            if (num == target)
            {
                return mid;
            }
            else if (num < target)
            {
                left = mid + 1;
            }
            else if (num > target)
            {
                right = mid - 1;
            }
        }
        return left;
    }
};