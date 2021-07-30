/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 * [medium]
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/
 */

// @lc code=start
#include<vector>
#include <algorithm>//max_element
using namespace std;
//动态规划
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return -1;
        vector<int> dp(n,0);
        for (int i = 0; i < n; i++)
        {
            dp[i]=1;
            for (int j = 0; j < i; j++)
            {
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
        
    }
};
//法二 贪心+二分
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return -1;
        vector<int> dp(n+1,0);
        int len=0;
        dp[0]=nums[0];
        for (int i = 1; i < n; i++)
        {
            if(nums[i]>dp[len]){//注意此处是dp
                dp[++len]=nums[i];
            }else{
                int left=0,right=len,pos=0;
                while(left<=right){
                    int mid=(left+right)>>1;
                    if(dp[mid]<nums[i]){//注意此处是dp
                        left=mid+1;
                        pos=left;
                    }else{
                        right=mid-1;
                    }
                }
                dp[pos]=nums[i];
            }
        }
        return len+1;
        
    }
};
// @lc code=end

