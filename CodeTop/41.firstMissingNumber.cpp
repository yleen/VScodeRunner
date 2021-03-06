/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 * [hard]
 * https://leetcode-cn.com/problems/first-missing-positive/
 */

// @lc code=start
//使用原地哈希法  好好体会思想
#include<vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0)
                nums[i]=n+1;
        }
        for(int i=0; i<n;i++){
            int num=abs(nums[i]);//?为啥一定得加abs
            if(num<=n){
                nums[num-1]=-abs(nums[num-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                return i+1;
        }
        return n+1;
    }
};
// @lc code=end

