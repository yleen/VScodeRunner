/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
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
            if(vis[i]||i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) continue;
            perm.push_back(nums[i]);
            vis[i]=1;
            backtrack(nums,perm,numList,first+1);
            vis[i]=0;
            perm.pop_back();
        }
    }

};
// @lc code=end

