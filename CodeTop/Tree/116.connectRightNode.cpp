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
        
    }

    void connectChildNode(Node* node1,Node* node2){
        
    }
};


// @lc code=end

