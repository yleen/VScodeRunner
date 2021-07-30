/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 * [easy]
 * https://leetcode-cn.com/problems/maximum-subarray/
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax=0;int sumMax=nums[0];
        for(int i=0;i<nums.size();i++){
            currMax=max(nums[i]+currMax,nums[i]);//当加了一个数n后的值还不如其本身大时就丢弃前面的和从这个数开始求和
            sumMax=max(currMax,sumMax);
        }
        return sumMax;
    }
};
// @lc code=end

