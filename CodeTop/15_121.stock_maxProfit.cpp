/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = prices[0];
        int maxMoney = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            minPrice=min(minPrice,prices[i]);
            maxMoney=max(maxMoney,prices[i]-minPrice);
        }
        return maxMoney;
    }
};
// @lc code=end
