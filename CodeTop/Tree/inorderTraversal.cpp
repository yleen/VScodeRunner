/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * [easy]
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
#include<stack>
using namespace std;

//迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> treeNum;
        if(root==nullptr)
            return treeNum;
        stack<TreeNode*> skNode;
        while(!skNode.empty()||root!=nullptr){
            while(root!=nullptr){
                skNode.push(root);
                root=root->left;
            }
            root=skNode.top();
            treeNum.push_back(root->val);
            skNode.pop();
            root=root->right;
        }
        return treeNum;
    }
};



//递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> treeNum;
        midTreeRecur(root,treeNum);
        return treeNum;
    }

    void midTreeRecur(TreeNode* root,vector<int>& treeNum){
        if(root==nullptr)
            return;
        midTreeRecur(root->left,treeNum);
        treeNum.push_back(root->val);
        midTreeRecur(root->right,treeNum);
    }

};


//Morris TOStudy
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                
                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    res.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
// @lc code=end

