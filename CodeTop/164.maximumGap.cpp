/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 * [hard]
 * https://leetcode-cn.com/problems/maximum-gap/solution/
 * meet with:云建信
 */

// @lc code=start
//应用桶排序思想
#include<vector>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if (n<2){
            return 0;
        }
        int minVal=*min_element(nums.begin(),nums.end());
        int maxVal=*max_element(nums.begin(),nums.end());
        int d=max(1,(maxVal-minVal)/(n-1));
        int bucketSize=(maxVal-minVal)/d+1;
        
        vector<pair<int,int>> bucket(bucketSize,{-1,-1});
        for(int i=0;i<n;i++){
            int idx=(nums[i]-minVal)/d;
            if(bucket[idx].first==-1){
                bucket[idx].first=nums[i];
                bucket[idx].second=nums[i];
            }else{
                bucket[idx].first=min(bucket[idx].first,nums[i]);
                bucket[idx].second=max(bucket[idx].second,nums[i]);
            }
        }
        int ret =0;
        int prev=-1;
        for(int i=0;i<bucketSize;i++){
            if(bucket[i].first==-1)
                continue;
            if(prev!=-1){
                ret=max(ret,bucket[i].first-bucket[prev].second);
            }
            prev=i;
        }
        return ret;
    }
};
// @lc code=end

