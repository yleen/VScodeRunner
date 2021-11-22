/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
    private:
        int maxSum = INT_MIN;

public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
    int maxGain(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftPath = max(maxGain(root->left), 0);//加max是因为结点包含负数
        int rightPath = max(maxGain(root->right), 0);

        int path = root->val + leftPath + rightPath;

        maxSum = max(path, maxSum);

        return root->val + max(leftPath, rightPath);
    }
};
// @lc code=end