/*
 * @lc app=leetcode.cn id=1116 lang=cpp
 *
 * [1116] 打印零与奇偶数
 * [medium]
 * https://leetcode-cn.com/problems/print-zero-even-odd/submissions/
 * meet with: 浩瀚深度
 */

// @lc code=start
// #include <mutex>//mutex
// using namespace std;
class ZeroEvenOdd {
private:
    int n,t;
    mutex l1,l2,l3;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        t=1;
        l2.lock();
        l3.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        int k=n;
        while(k){
            l1.lock();
            printNumber(0);
            --k;
            l2.unlock();
            if(!k)return;
            l1.lock();
            printNumber(0);
            --k;
            l3.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        int k=n/2;
        while(k--){
            l3.lock();
            printNumber(t);
            ++t;
            l1.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        int k=(n+1)/2;
        while (k--)
        {
            l2.lock();
            printNumber(t);
            ++t;
            l1.unlock();
        }
        
    }
};
// @lc code=end

