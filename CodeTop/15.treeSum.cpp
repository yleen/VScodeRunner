/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 * [medium]
 * https://leetcode-cn.com/problems/3sum/
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sumList;
        sort(nums.begin(),nums.end());
        
        for(int first=0;first<nums.size();first++){
            if(nums[first]>0) break;
            if(first>0&&nums[first]==nums[first-1]) continue;
            int target=-nums[first];
            int third=nums.size()-1;
            for(int second=first+1;second<nums.size();second++){
                if(second>first+1&&nums[second]==nums[second-1]) continue;
                while(second<third&&nums[second]+nums[third]>target)
                    third--;
                if(second==third)
                    break;
                if(nums[second]+nums[third]==target){
                    sumList.push_back({nums[first],nums[second],nums[third]});
                }
            }
        }

        return sumList;
    }
};
// @lc code=end

