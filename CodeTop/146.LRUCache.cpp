/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 * https://leetcode-cn.com/problems/lru-cache/
 * [medium]
 */

// @lc code=start
#define NULL 0
#include<unordered_map>

using namespace std;
struct DoubleLinkList{
    DoubleLinkList* pre;
    DoubleLinkList* next;
    int key;
    int value;
    DoubleLinkList(int key,int value):key(key),value(value),pre(NULL),next(NULL){};
};


struct DoubleLinkList{
    DoubleLinkList* prev;
    DoubleLinkList* next;
    int key;
    int value;
    DoubleLinkList(int key,int value):key(key),value(value),prev(NULL),next(NULL){};
};

class LRUCache {
    DoubleLinkList* head;
    DoubleLinkList* tail;
    unordered_map<int,DoubleLinkList*> memory;

    int cacheCapacity=0;
public:
    LRUCache(int capacity) {
        cacheCapacity=capacity;
        head=new DoubleLinkList(-1,-1);
        tail=new DoubleLinkList(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(memory.find(key)!=memory.end()){
            DoubleLinkList* node= updateStatus(key);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(memory.find(key)!=memory.end()){
            DoubleLinkList* node=updateStatus(key);
            node->value=value;
            return;//这里不要丢了！！
        }
        if(memory.size()==cacheCapacity){
            int topKey =head->next->key;
            removeNode(head->next);
            memory.erase(topKey);
        }
        DoubleLinkList* node=new DoubleLinkList(key,value);
        pushNode(node);
        memory[key]=node;
    }

    DoubleLinkList* updateStatus(int key){
        DoubleLinkList* node=memory[key];
        removeNode(node);
        pushNode(node);
        return node;
    }

    void removeNode(DoubleLinkList* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        node->next=NULL;
        node->prev=NULL;
    }

    void pushNode(DoubleLinkList* node){
        tail->prev->next=node;
        node->prev=tail->prev;
        tail->prev=node;
        node->next=tail;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

