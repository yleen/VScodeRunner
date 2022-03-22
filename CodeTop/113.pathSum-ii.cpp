/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 * [Medium]
 * https://leetcode-cn.com/problems/path-sum-ii/
 * 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
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
private:
    vector<vector<int>> pathSums;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return pathSums;
        }
        dfs(root, targetSum);
        return pathSums;
    }
    void dfs(TreeNode* root, int targetSum){
        targetSum -= root->val;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(targetSum == 0){
                pathSums.push_back(path);
            }
        }
        if(root->left){
            dfs(root->left, targetSum);
        }
        if(root->right){
            dfs(root->right, targetSum);
        }
        path.pop_back();
    }
};
// @lc code=end

#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//层序遍历 bfs //TOTrain
class Solution {
private:
    unordered_map<TreeNode*,TreeNode*> parent;
    vector<int> getPath(TreeNode* node){
        vector<int> path;
        while (node != nullptr)
        {
            path.push_back(node->val);
            node = parent[node];
        }
        reverse(path.begin(),path.end());
        return path;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> pathSums;
        queue<TreeNode*> q_node;
        queue<int> q_sum;
        if(root != nullptr){
            q_node.push(root);
        }
        q_sum.push(0);
        while(!q_node.empty()){
            TreeNode* node = q_node.front();q_node.pop();
            int pathSum = q_sum.front() + node->val; q_sum.pop();
            if(node->left){
                q_node.push(node->left);
                q_sum.push(pathSum);
                parent[node->left] = node;
            }
            if(node->right){
                q_node.push(node->right);
                q_sum.push(pathSum);
                parent[node->right] = node;
            }
            if(node->left == nullptr && node->right == nullptr){
                if(pathSum == targetSum){
                    pathSums.push_back(getPath(node));
                }
            }
        }
        return pathSums;
    }
};

//dfs
class Solution {
private:
    vector<vector<int>> pathSums;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return pathSums;
        }
        dfs(root,targetSum);
        return pathSums;
    }
    // void dfs(TreeNode* root,int pathSum, int targetSum, vector<int> path){
    void dfs(TreeNode* root, int targetSum){
        targetSum -=root->val;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            // if(pathSum == targetSum){
            if(targetSum == 0){
                pathSums.push_back(path);
            }
        }
        if(root->left){
            dfs(root->left,targetSum);
        }
        if(root->right){
            dfs(root->right,targetSum);
        }
        path.pop_back();//注意如果path是全局变量的话需要及时清空
    }
};