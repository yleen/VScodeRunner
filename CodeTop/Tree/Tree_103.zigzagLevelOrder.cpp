/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
 * [medium]
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
#include<vector>
#include<queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        queue<TreeNode*> qTree;
        bool isLeft=false;
        qTree.push(root);
        while (!qTree.empty())
        {  
           deque<int> tier;
           int size=qTree.size();
           while (size>0)
           {
               size--;
               TreeNode* node=qTree.front();
               qTree.pop();
               if(isLeft){
                   tier.push_front(node->val);
               }else
               {
                   tier.push_back(node->val);
               }
               if(node->left) qTree.push(node->left);
               if(node->right) qTree.push(node->right);
           }
           res.emplace_back(vector<int>{tier.begin(),tier.end()});
           isLeft=!isLeft;
        }
        return res;
    }
};
// @lc code=end
