/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
 * 这个问题是受到 Max Howell 的 原问题 启发的 ：
 * 
 * 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//前序遍历
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)
            return root;
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        root->left=right;
        root->right=left;
        invertTree(left);
        invertTree(right);
        return root;
    }
};
//中序遍历
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)
            return root;
        invertTree(root->left);;
        TreeNode* right=root->right;
        root->right=root->left;
        root->left=right;
        invertTree(root->left);
        return root;
    }
};
//后序遍历
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)
            return root;
        TreeNode* left=invertTree(root->left);;
        TreeNode* right=invertTree(root->right);
        root->left=right;
        root->right=left;
        return root;
    }
};
//层序遍历
#include<queue> 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)
            return root;
        std::queue<TreeNode*> qTree;
        qTree.push(root);
        while(!qTree.empty()){
            int size=qTree.size();
            for(int i=0;i<size;i++){
                TreeNode* node=qTree.front();qTree.pop();
                TreeNode* left=node->left;
                TreeNode* right=node->right;
                node->left=right;
                node->right=left;
                if(left)
                    qTree.push(left);
                if(right)
                    qTree.push(right);
            }
        }
        return root;
    }
};
// @lc code=end

