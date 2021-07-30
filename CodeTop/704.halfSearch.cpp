/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 * [easy]
 * https://leetcode-cn.com/problems/binary-search/
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,pivot=0,right=nums.size()-1;
        while (left<=right)
        {
            pivot=left+(right-left)/2;
            if(nums[pivot]==target) return pivot;
            if(nums[pivot]>target) {
                right=pivot-1;
            }
            else{
                left=pivot+1;
            }
        }
        return -1;
        
    }
};
// @lc code=end

