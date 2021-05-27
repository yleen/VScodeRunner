/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include<vector>
using namespace std;
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildMaxTree(nums,0,nums.size()-1);
    }
    TreeNode* buildMaxTree(vector<int>& nums,int start,int end){
        if(start>end)
            return nullptr;
        auto res=maxIndex(nums,start,end);
        TreeNode* root=new TreeNode(res.first);
        root->left=buildMaxTree(nums,start,res.second-1);
        root->right=buildMaxTree(nums,res.second+1,end);
        return root;
    }
    pair<int,int> maxIndex(vector<int>& nums,int start,int end){
        int max=nums[start],index=start;
        for (int i = start; i <= end; i++)
        {
            if(nums[i]>max){
                max=nums[i];
                index=i;
            }
        }
        return {max,index};
    }
};
// @lc code=end

