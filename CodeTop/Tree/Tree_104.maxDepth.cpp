/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
#include <algorithm>
#include <queue>
using namespace std;
//递归法
class Solution {
public:
    int maxDepthRecur(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        return max(maxDepthRecur(root->left),maxDepthRecur(root->right))+1;
    }
};

//广度优先法
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        queue<TreeNode*> qTree;
        qTree.push(root);
        int deepSize=0;
        while (!qTree.empty())
        {
            int size=qTree.size();
            while (size>0)
            {
                TreeNode* node=qTree.front();
                qTree.pop();
                if(node->left){
                    qTree.push(node->left);
                }
                if(node->right){
                    qTree.push(node->right);
                }
                size--;
            }
            deepSize++;
            
        }
        return deepSize;
    }
};
// @lc code=end

