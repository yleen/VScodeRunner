/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
#include<queue>
using namespace std;

//方法 层序遍历 保存最后一个节点
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> qTree;
        qTree.push(root);
        while(!qTree.empty()){
            int size=qTree.size();
            res.push_back(qTree.front()->val);//注意此处之所以直接添加是因为 push的时候先加的右节点再加的左节点 即靠右的节点在前
            for(int i=0;i<size;i++){
                TreeNode* node=qTree.front();qTree.pop();
                if(node->right)qTree.push(node->right);
                if(node->left)qTree.push(node->left);
            }
        }
        return res;
    }
};
// @lc code=end

