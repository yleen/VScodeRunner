/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * [medium]
 * https://leetcode-cn.com/problems/permutations-ii/
 */

// @lc code=start
class Solution {
    vector<int> vis;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vis.resize(n);
        vector<vector<int>> numsList;
        vector<int> prem;
        backtrack(nums, numsList, prem, 0);
        return numsList;
    }
    void backtrack(vector<int>& nums, vector<vector<int>>& numsList, vector<int>& prem, int first){
        if(first == nums.size()){
            numsList.push_back(prem);
        }
        for(int i = 0; i < nums.size(); i++){
            if(vis[i] || i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]){
                continue;
            }
            prem.push_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, numsList, prem, first + 1);
            vis[i] = 0;
            prem.pop_back();
        }
    }
};
// @lc code=end
#include<vector>
#include <algorithm>//sort
using namespace std;

class Solution {
    vector<int> vis;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vis.resize(nums.size());
        vector<vector<int>> numsList;
        vector<int> perm;
        backtrack(nums,perm,numsList,0);
        return numsList;
    }

    void backtrack(vector<int>& nums,vector<int>& perm,vector<vector<int>>& numList,int first){
        if(first==nums.size()){
            numList.push_back(perm);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(vis[i]||i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) continue;//? 关于为什么是 !vis[i - 1] 而不是vis[i - 1] 有很多讨论 大概意思是加！会判断之前是否已访问过 因为回溯结束后都会置为0 但是不加!就会在当前回溯判断，具体还不是很清楚 只知道加！效率更高
            perm.push_back(nums[i]);
            vis[i]=1;
            backtrack(nums,perm,numList,first+1);
            vis[i]=0;
            perm.pop_back();
        }
    }

};
