/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#define NULL 0
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
// 层次遍历
#include<queue>
using namespace std;
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
        return root;
        Node* head=root;
        queue<Node*> qRoot;
        qRoot.push(root);
        while(!qRoot.empty()){
            int size=qRoot.size();
            Node* currNode=qRoot.front();
            for(int i=0;i<size;i++){
                Node* newNode=qRoot.front();qRoot.pop();
                if(i>0){
                    currNode->next=newNode;
                    currNode=newNode;
                }
                if(newNode->left)qRoot.push(newNode->left);
                if(newNode->right)qRoot.push(newNode->right);
            }
        }
        return head;
    }
};

//递归式
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)
            return root;
        connectChildNode(root->left,root->right);
        return root;
    }

    void connectChildNode(Node* node1,Node* node2){
        if(node1==nullptr||node2==nullptr)
            return;
        node1->next=node2;
        connectChildNode(node1->left,node1->right);
        connectChildNode(node2->left,node2->right);
        connectChildNode(node1->right,node2->left);
    }
};
//迭代式
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        Node* prev=root;
        while(prev->left!=NULL){
            Node* tmp=prev;
            while(tmp!=NULL){
                tmp->left->next=tmp->right;
                if(tmp->next!=NULL){
                    tmp->right->next=tmp->next->left;
                }
                tmp=tmp->next;
            }
            prev=prev->left;
        }
        return root;
    }
};

//dfs 天秀解法
class Solution {
public:
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }

    void dfs(Node* node){
        if(node==NULL)
            return;
        Node* left=node->left;
        Node* right=node->right;
        while(left!=NULL){
            left->next=right;
            left=left->right;
            right=right->left;
        }
        dfs(node->left);
        dfs(node->right);
    }
};
// @lc code=end

