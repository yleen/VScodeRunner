/*
    二叉树前序遍历
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

//迭代法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> treeNum;
        if(root==nullptr)
            return treeNum;
        stack<TreeNode*> skNode;
        while(!skNode.empty()||root!=nullptr){
            while(root!=nullptr){
                treeNum.push_back(root->val);
                skNode.push(root);
                root=root->left;
            }
            root=skNode.top();
            skNode.pop();
            root=root->right;
            
        }
        return treeNum;
    }
};

//递归法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> treeNum;
        preTree(root,treeNum);
        return treeNum;
    }

    void preTree(TreeNode* root,vector<int>& treeNum){
        if(root==nullptr)
            return;
        treeNum.push_back(root->val);
        preTree(root->left,treeNum);
        preTree(root->right,treeNum);
    }
};

//Morris 遍历   待学

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        TreeNode *p1 = root, *p2 = nullptr;

        while (p1 != nullptr) {
            p2 = p1->left;
            if (p2 != nullptr) {
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    res.emplace_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                }
            } else {
                res.emplace_back(p1->val);
            }
            p1 = p1->right;
        }
        return res;
    }
};