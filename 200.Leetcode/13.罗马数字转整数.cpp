/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        int length = s.length();
        if (length == 1)
        {
            return getValue(s[0]);
        }

        int ans = 0, value1, value2;
        for (int i = 0; i < length; i++)
        {
            value1 = getValue(s[i]);
            if (i + 1 < length)
            {
                value2 = getValue(s[i + 1]);
                if (value1 < value2)
                {
                    ans -= value1;
                }
                else
                {
                    ans += value1;
                }
            }
            else
            {
                ans += value1;
            }
        }

        return ans;
    }

    int getValue(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
};
// @lc code=end
