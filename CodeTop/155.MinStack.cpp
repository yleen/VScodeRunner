/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;
//维护两个表
class MinStack {
public:
    vector<int> content;
    vector<int> min_val;
    MinStack() {
        min_val.push_back(INT_MAX);
    }
    
    void push(int val) {
        content.push_back(val);
        min_val.push_back(min(min_val.back(),val));
    }
    
    void pop() {
        content.pop_back();
        min_val.pop_back();
    }
    
    int top() {
        return content.back();
    }
    
    int getMin() {
        return min_val.back();
    }
};


// 不用额外空间  但其实也是需要long空间的 主要是测试用例的问题 如果用例数值不大可以把long改为int
class MinStack {
public:
    vector<long> content;
    // vector<double> content;
    // int min_val;
    long min_val
    MinStack() {
    }
    
    void push(int val) {
        if(content.size() == 0){
            min_val = val;
            content.push_back(0);
        }else{
            content.push_back(val - min_val);
            // content.push_back((double)val - (double)min_val);
            if(min_val > val){
                min_val = val;
            }
        }
    }
    
    void pop() {
        if(content.back() < 0){
            min_val = min_val - content.back();
        }
        content.pop_back();
    }
    
    int top() {
        return content.back() < 0 ? min_val : content.back() + min_val;
    }
    
    int getMin() {
        return min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end