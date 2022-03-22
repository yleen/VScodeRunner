/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 * [Medium]
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr)
        {
            if(curr->left != nullptr){
                TreeNode* next = curr->left;
                TreeNode* prev = next;
                while (prev->right != nullptr)
                {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
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
#include<stack>
#include<vector>
using namespace std;
//经典法 前序遍历出顺序，再依次展开
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        vector<TreeNode*> link;
        stack<TreeNode*> sk;
        while (root != nullptr || !sk.empty())
        {
            while (root != nullptr)
            {
                sk.push(root);
                link.push_back(root);
                root = root->left;
            }
            root = sk.top();sk.pop();
            root = root->right;
        }
        int size = link.size();
        for(int i = 1; i < size; i++){
            TreeNode* prev = link[i - 1];
            TreeNode* curr = link[i];
            prev->right = curr;
            prev->left = nullptr;
        }
    }
};

//前序和展开同步进行
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        TreeNode* prev = nullptr;
        stack<TreeNode*> sk;
        sk.push(root);
        while (!sk.empty())
        {
            TreeNode* curr = sk.top(); sk.pop();
            if(prev != nullptr){
                prev->right = curr;
                prev->left = nullptr;
            }
            if(curr->right){
                sk.push(curr->right);
            }
            if(curr->left){
                sk.push(curr->left);
            }
            prev = curr;
        }
    }
};

//递归式
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = nullptr;
        root->right = left;
        TreeNode* p = root;
        while (p->right != nullptr)
        {
            p = p->right;
        }
        p->right = right;
    }
};

//此方法时间复杂度o(n) 空间复杂度o(1)最符合题意
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr)
        {
            if(curr->left != nullptr){
                TreeNode* next = curr->left;
                TreeNode* prev = next;
                while (prev->right != nullptr)
                {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }
};