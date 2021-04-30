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
当越过叶节点，则直接返回 nullnull ；
当 rootroot 等于 p, qp,q ，则直接返回 rootroot ；
递推工作：
开启递归左子节点，返回值记为 leftleft ；
开启递归右子节点，返回值记为 rightright ；
返回值： 根据 leftleft 和 rightright ，可展开为四种情况；
当 leftleft 和 rightright 同时为空 ：说明 rootroot 的左 / 右子树中都不包含 p,qp,q ，返回 nullnull ；
当 leftleft 和 rightright 同时不为空 ：说明 p, qp,q 分列在 rootroot 的 异侧 （分别在 左 / 右子树），因此 rootroot 为最近公共祖先，返回 rootroot ；
当 leftleft 为空 ，rightright 不为空 ：p,qp,q 都不在 rootroot 的左子树中，直接返回 rightright 。具体可分为两种情况：
p,qp,q 其中一个在 rootroot 的 右子树 中，此时 rightright 指向 pp（假设为 pp ）；
p,qp,q 两节点都在 rootroot 的 右子树 中，此时的 rightright 指向 最近公共祖先节点 ；
当 leftleft 不为空 ， rightright 为空 ：与情况 3. 同理；
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
      if(left!=NULL)
        return left;
      if(right!=NULL)
        return right;
      return NULL;
    }
};

// @lc code=end

