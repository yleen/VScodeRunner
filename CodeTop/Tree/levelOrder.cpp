/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include<vector>
#include<queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//法一 加子节点
class Solution
{
public:
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > res;
        if (!root)
            return res;
        queue<TreeNode *> qTree;
        qTree.push(root);
        res.push_back({root->val});
        while (!qTree.empty())
        {
            int size = qTree.size();
            vector<int> tier;
            while (size > 0)
            {
                size--;
                TreeNode *node = qTree.front();
                qTree.pop();
                if (node->left || node->right)
                {
                    if (node->left)
                    {
                        tier.push_back(node->left->val);
                        qTree.push(node->left);
                    }
                    if (node->right)
                    {
                        tier.push_back(node->right->val);
                        qTree.push(node->right);
                    }
                }
            }
            if (tier.size() > 0)
                res.push_back(tier);
        }
        return res;
    }
};
//法二 加父节点
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root)
        return res;
        queue<TreeNode*> qTree;
        qTree.push(root);
        while(!qTree.empty()){
            int size=qTree.size();
            vector<int> tier;
            while(size>0){
                size--;
                TreeNode* node=qTree.front();
                tier.push_back(node->val);
                qTree.pop();
                if(node->left)  qTree.push(node->left);
                if(node->right) qTree.push(node->right);
            }
            res.push_back(tier);
        }
        return res;
    }
};
// @lc code=end
