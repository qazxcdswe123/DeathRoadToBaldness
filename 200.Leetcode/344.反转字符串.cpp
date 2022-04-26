/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution
{
public:
    void reverseString(vector<char> &s, int k = 0)
    {
        int n = s.size();
        if (!n)
        {
            return;
        }

        if (k >= s.size() / 2)
        {
            return;
        }

        swap(s[n - 1 - k], s[k]);
        reverseString(s, k + 1);
    }
};
// @lc code=end
