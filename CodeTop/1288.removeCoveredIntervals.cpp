/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 * [easy]
 * https://leetcode-cn.com/problems/remove-covered-intervals/
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
    static bool compare(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return a[0] <= b[0];
    }

public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        int count = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][1] <= end)
            {
                count--;
            }
            else
            {
                end = intervals[i][1];
            }
        }
        return count;
    }
};
// @lc code=end
