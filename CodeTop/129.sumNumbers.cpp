/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
#include<vector>
#include<stack>
#include<queue>
using namespace std;
class Solution {
public:
    int dfs(TreeNode* root, int sum){
        if(root == nullptr){
            return 0;
        }
        sum = sum * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr){
            return sum;
        }
        return dfs(root->left, sum) + dfs(root->right, sum);
    }

    int bfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        queue<TreeNode*> qNode;
        qNode.push(root);
        queue<int> qNum;
        qNum.push(root->val);
        int sum = 0;
        while(!qNode.empty()){
            TreeNode* node = qNode.front();
            qNode.pop();
            int num = qNum.front();
            qNum.pop();
            if(node->left == nullptr && node->right == nullptr){
                sum += num;
            }else{
                if(node->left != nullptr){
                    qNode.push(node->left);
                    qNum.push(num * 10 + node->left->val);
                }
                if(node->right != nullptr){
                    qNode.push(node->right);
                    qNum.push(num * 10 + node->right->val);
                }
            }
        }
        return sum;
    }
    int sumNumbers(TreeNode* root) {
        // return dfs(root,0);
        return bfs(root);
    }
};

// @lc code=end