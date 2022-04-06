/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size == 0)
        {
            return "";
        }
        int count = strs.size();
        int length = strs[0].size();
        for (int i = 0; i < count; i++)
        {
            char c = strs[0][i];
        }
    }
};
// @lc code=end
