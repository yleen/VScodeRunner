/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> numsList;
        backtrack(nums,numsList,0);
        return numsList;
    }

    void backtrack(vector<int>& nums,vector<vector<int>>& numsList,int first){
        if(first==nums.size()){
            numsList.push_back(nums);
        }

        for(int i=first;i<nums.size();i++){
            swap(nums[first],nums[i]);
            backtrack(nums,numsList,first+1);
            swap(nums[first],nums[i]);
        }
    }
};
// @lc code=end

