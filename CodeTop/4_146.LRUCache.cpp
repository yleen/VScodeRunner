/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
#include<unordered_map>

using namespace std;
struct DoubleLinkList{
    DoubleLinkList* pre;
    DoubleLinkList* next;
    int key;
    int value;
    DoubleLinkList(int key,int value):key(key),value(value),pre(NULL),next(NULL){};
};


class LRUCache {
public:

    DoubleLinkList* head;
    DoubleLinkList* tail;

    unordered_map<int,DoubleLinkList*> memory;

    int cacheCapacity=0;
    LRUCache(int capacity) {
        cacheCapacity=capacity;
        head=new DoubleLinkList(-1,-1);
        tail=new DoubleLinkList(-1,-1);
        head->next=tail;
        tail->pre=head;
    }
    
    int get(int key) {
        if(memory.find(key)!=memory.end()){
            DoubleLinkList* node=memory[key];
            removeNode(node);
            pushNode(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(memory.find(key)!=memory.end()){
            DoubleLinkList* node=memory[key];
            removeNode(node);
            pushNode(node);
            node->value=value;
            return;
        }
        if(memory.size()==cacheCapacity){
            DoubleLinkList* node=head->next;
            int topKey=node->key;
            removeNode(node);
            memory.erase(topKey);
        }
        DoubleLinkList* node =new DoubleLinkList(key,value);
        pushNode(node);
        memory[key]=node;

    }

    void removeNode(DoubleLinkList* node){
        node->pre->next=node->next;
        node->next->pre=node->pre;
    }

    void pushNode(DoubleLinkList* node){
        node->pre=tail->pre;
        tail->pre->next=node;
        node->next=tail;
        tail->pre=node;
    }




};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

