/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution
{
public:
    bool binarySearch(vector<int> &array, int target)
    {
        }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        if (m == 1)
        {
            int left = 0, right = n - 1;
            while (left <= right)
            {
                int middle = left + (right - left) / 2;
                if (matrix[0][middle] == target)
                {
                    return true;
                }
                else if (matrix[0][middle] > target)
                {
                    right = middle - 1;
                }
                else
                {
                    left = middle + 1;
                }
            }
        }
    }
};
// @lc code=end
