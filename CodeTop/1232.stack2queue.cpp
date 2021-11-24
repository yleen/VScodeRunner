/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 * [easy]
 * https://leetcode-cn.com/problems/implement-queue-using-stacks/
 */
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=start

//简易形式  直接用库中的栈
#include <stack>
using namespace std;
class MyQueue
{
private:
    stack<int> stackPush;
    stack<int> stackPop;
    void transStack()
    {
        while (!stackPush.empty())
        {
            stackPop.push(stackPush.top());
            stackPush.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        stackPush.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (stackPop.empty())
        {
            transStack();
        }
        int res = stackPop.top();
        stackPop.pop();
        return res;
    }

    /** Get the front element. */
    int peek()
    {
        if (stackPop.empty())
        {
            transStack();
        }
        return stackPop.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return stackPop.empty() && stackPush.empty();
    }
};

// @lc code=end