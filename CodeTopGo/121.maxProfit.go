/*
 * @lc app=leetcode.cn id=121 lang=golang
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
func maxProfit(prices []int) int {
	curr := prices[0]
	max := 0
	for i := 1; i < len(prices); i++{
		if max < prices[i] - curr{
			max = prices[i] - curr
		}
		if prices[i] < curr{
			curr = prices[i]
		}
	}
	return max;
}
// @lc code=end

