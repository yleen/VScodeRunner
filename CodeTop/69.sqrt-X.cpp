/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 * [easy]
 * https://leetcode-cn.com/problems/sqrtx/
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        double C = x;
        double x0 = x;
        while (true)
        {
            double xi = 0.5 * (x0 + C / x0);
            if(fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};
// @lc code=end

//二分法
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int ans = 0;
        while (left <= right)
        {
            int mid = (left+right) >> 1;
            if((long)mid * mid <= x){
                left = mid + 1;
                ans = mid;// 注意ans要放在这里
            }else{
                right = mid-1;
            }
        }
        return ans;
    }
};

//牛顿分析法 ？
#include <math.h> //fabs
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};