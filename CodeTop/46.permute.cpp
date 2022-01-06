/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * [medium]
 * https://leetcode-cn.com/problems/permutations/
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> numsList;
        backtrack(nums, numsList, 0);
        return numsList;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& numsList, int first){
        if(first == nums.size()){
            numsList.push_back(nums);
        }
        for(int i = first; i < nums.size(); i++){
            swap(nums[i], nums[first]);
            backtrack(nums, numsList, first + 1);
            swap(nums[i], nums[first]);
        }
    }
};
// @lc code=end

#include <iostream>
#include <vector>

using namespace std;
//背就vans了
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