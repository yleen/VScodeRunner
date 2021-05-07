/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include<vector>
#include <algorithm>//max_element
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return -1;
        vector<int> pos(n,0);
        for (int i = 0; i < n; i++)
        {
            pos[i]=1;
            for (int j = 0; j < i; j++)
            {
                if(nums[j]<nums[i]){
                    pos[i]=max(pos[i],pos[j]+1);
                }
            }
        }
        return *max_element(pos.begin(),pos.end());
        
    }
};
// @lc code=end

