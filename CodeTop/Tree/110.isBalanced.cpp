/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <stdlib.h> 
#include <algorithm> 
using namespace std;
// //递归式 1 从上往下
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if(root==nullptr)
            return true;
        else{
            return abs(Height(root->left)-Height(root->right))<=1&&isBalanced(root->left)&&isBalanced(root->right);
        }
    }
    int Height(TreeNode* root){
        if(root==nullptr)
            return 0;
        else{
            return max(Height(root->left),Height(root->right))+1;
        }
    }
};


//递归式2 从下往上
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return height(root) >= 0;
    }
    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (abs(left - right) > 1 || left == -1 || right == -1)
        {
            return -1;
        }
        else
        {
            return max(left, right) + 1;
        }
    }
};
// @lc code=end
