/*
    二叉树后序遍历
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
#include <algorithm>//reverse
using namespace std;

//迭代 TOStudy
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> treeNum;
        if(root==nullptr)
            return treeNum;
        stack<TreeNode*> skNode;
        TreeNode* prv=nullptr;
        while(!skNode.empty()||root!=nullptr){
            while(root!=nullptr){
                skNode.push(root);
                root=root->left;
            }
            root=skNode.top();
            skNode.pop();
            if(root->right==nullptr||prv==root->right){
                treeNum.push_back(root->val);
                prv=root;
                root=nullptr;
                
            }else{
                skNode.push(root);
                root=root->right;
            }
        }
        return treeNum;

    }
};
//迭代 此方法较为简便
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> treeNum;
        if(root==nullptr)
            return treeNum;
        stack<TreeNode*> skNode;
        skNode.push(root);
        while(!skNode.empty()){
            TreeNode* node=skNode.top();skNode.pop();
            treeNum.push_back(node->val);
            if(node->left)skNode.push(node->left);//注意与前序遍历的区别 此处先push left
            if(node->right)skNode.push(node->right);
        }
        reverse(treeNum.begin(),treeNum.end());//最后要逆转
        return treeNum;
    }
};



//递归
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> treeNum;
        postTree(root,treeNum);
        return treeNum;
    }

    void postTree(TreeNode* root,vector<int>& treeNum){
        if(root==nullptr)
            return;
        postTree(root->left,treeNum);
        postTree(root->right,treeNum);
        treeNum.push_back(root->val);
    }
};

//Morris TOStudy

class Solution {
public:
    void addPath(vector<int> &vec, TreeNode *node) {
        int count = 0;
        while (node != nullptr) {
            ++count;
            vec.emplace_back(node->val);
            node = node->right;
        }
        reverse(vec.end() - count, vec.end());
    }

    vector<int> postorderTraversal(TreeNode *root) {
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
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                    addPath(res, p1->left);
                }
            }
            p1 = p1->right;
        }
        addPath(res, root);
        return res;
    }
};