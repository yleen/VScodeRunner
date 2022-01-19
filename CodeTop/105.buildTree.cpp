/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 * [Medium]
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()){
            return nullptr;
        }
        stack<TreeNode*> sk;
        TreeNode* root = new TreeNode(preorder[0]);
        sk.push(root);
        int in_index = 0;
        for(int i = 1; i < preorder.size(); i++){
            int node_val = preorder[i];
            TreeNode* curr_node = sk.top();
            if(inorder[in_index] != curr_node->val){
                curr_node->left = new TreeNode(node_val);
                sk.push(curr_node->left);
            }else{
                while (!sk.empty() && sk.top()->val == inorder[in_index])
                {
                    curr_node = sk.top();
                    sk.pop();
                    in_index++;
                }
                curr_node->right = new TreeNode(node_val);
                sk.push(curr_node->right);
            }
        }
        return root;
    }
};
// @lc code=end
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;
//递归
class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++){
            index[inorder[i]] = i;
        }
        return reConstructBinaryTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
    TreeNode* reConstructBinaryTree(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd){
        if(preStart > preEnd || inStart > inEnd){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);//获取先序遍历第一个元素， 第一个是根节点
        int in_index = index[preorder[preStart]];//获取中序遍历根节点索引
        //以获取的root节点为分界，计算出节点左边和右边的数组范围，前序和中序的范围不同，通过中序中节点的索引进行计算
        root->left = reConstructBinaryTree(preorder, inorder, preStart + 1, preStart + in_index - inStart, inStart, in_index - 1);
        root->right = reConstructBinaryTree(preorder, inorder, preStart + in_index - inStart + 1, preEnd, in_index + 1, inEnd);
        return root;
    }
};
//迭代
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()){
            return nullptr;
        }
        stack<TreeNode*> sk;
        TreeNode* root = new TreeNode(preorder[0]);
        sk.push(root);
        int in_index = 0;
        for(int i = 1; i < preorder.size(); i++){
            int node_val = preorder[i];
            TreeNode* curr_node = sk.top();
            if(inorder[in_index] != curr_node->val){
                curr_node->left = new TreeNode(node_val);
                sk.push(curr_node->left);
            }else{
                while (!sk.empty() && sk.top()->val == inorder[in_index])
                {
                    curr_node = sk.top();
                    sk.pop();
                    in_index++;
                }
                curr_node->right = new TreeNode(node_val);
                sk.push(curr_node->right);
            }
        }
        return root;
    }
};