/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameter;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        deepSize(root);
        return diameter;
    }
    int deepSize(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int leftSize = deepSize(node->left);
        int rightSize = deepSize(node->right);
        int maxSize = max(leftSize,rightSize);
        diameter = max(diameter, leftSize + rightSize);
        return maxSize + 1;
    }
};
// @lc code=end

