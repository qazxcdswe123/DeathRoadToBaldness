/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int length = nums.size();

        int count = 0;

        for (auto i : nums)
        {
            if (i != val)
            {
                nums[count++] = i;
            }
        }
        return count;
    }
};
// @lc code=end
