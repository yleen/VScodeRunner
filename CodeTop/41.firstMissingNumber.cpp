/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * [hard]
 * https://leetcode-cn.com/problems/first-missing-positive/
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

    }
};
// @lc code=end

//使用原地哈希法  好好体会思想
#include<vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] <= 0){
                nums[i] = n + 1;
            }
        }

        for(int j = 0; j < n; j++){
            int val = abs(nums[j]);//?为啥一定得加abs： 因为下面将原数组中的正数都标记为负数，最后遍历时遇到第一个正数就是缺失的数
            if(val <= n){
                nums[val - 1] = -abs(nums[val - 1]);
            }
        }
        for(int k = 0; k < n; k++){
            if(nums[k] > 0){//写成>=也能过 但这样不严谨，数组中已经没有等于0的数了
                return k + 1;
            }
        }
        return n + 1;
    }
};