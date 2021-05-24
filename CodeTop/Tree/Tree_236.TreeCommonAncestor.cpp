/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdlib.h> //NULL
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
#include<unordered_map>
using namespace std;
// dfs法
class Solution {
private:
  unordered_map<int,TreeNode*> father; //题中说明root->val都不相等  否则的话需要将int改为TreeNode*
  unordered_map<int,bool> visit;
  void dfs(TreeNode* root){
    if(root->left){
        father[root->left->val]=root;
        dfs(root->left);
    }
    if(root->right)
    {
        father[root->right->val]=root;
        dfs(root->right);
    }
  }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        father[root->val]=NULL;
        dfs(root);
        while(p){
          visit[p->val]=true;
          p=father[p->val];
        }
        while(q){
          if(visit[q->val]) return q;
          q=father[q->val];
        }
        return nullptr;
    }
};
//递归  后序遍历思想
/*
 终止条件：
当越过叶节点，则直接返回 null ；
当 root 等于 p, q ，则直接返回 root ；
递推工作：
开启递归左子节点，返回值记为 left ；
开启递归右子节点，返回值记为 right ；
返回值： 根据 left 和 right ，可展开为四种情况；
当 left 和 right 同时为空 ：说明 root 的左 / 右子树中都不包含 p,q ，返回 null ；
当 left 和 right 同时不为空 ：说明 p, q 分列在 root 的 异侧 （分别在 左 / 右子树），因此 root 为最近公共祖先，返回 root ；
当 left 为空 ，right 不为空 ：p,q 都不在 root 的左子树中，直接返回 right 。具体可分为两种情况：
p,q 其中一个在 root 的 右子树 中，此时 right 指向 p（假设为 p ）；
p,q 两节点都在 root 的 右子树 中，此时的 right 指向 最近公共祖先节点 ；
当 left 不为空 ， right 为空 ：与情况 3. 同理；
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(root==NULL)
        return NULL;
      if(root==p||root==q)
        return root;
      
      TreeNode* left=lowestCommonAncestor(root->left,p,q);
      TreeNode* right=lowestCommonAncestor(root->right,p,q);
      if(left!=NULL&&right!=NULL)
        return root;
      if(left!=NULL)//right ==null 说明root的右递归最终为null 即递归到底没找到p和q  也就是说p和q不在右子树中
        return left;
      if(right!=NULL)
        return right;
      return NULL;
    }
};

// @lc code=end

