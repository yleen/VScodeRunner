/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 * [medium]
 * https://leetcode-cn.com/problems/string-to-integer-atoi/
 */

// @lc code=start
#define INT_MAX  2147483648
#define INT_MIN  -2147483648
#include <string>
using namespace std;
class Solution
{
    bool MaxLarge(long long num)
    {
        return num >= INT_MAX || num <= INT_MIN;
    }

public:
    int myAtoi(string s)
    {
        int left=0;
        int right=s.size();
        while (left<right&&s[left]==' ')left++;
        int signal=1;
        if(s[left]=='-'){
            signal=-1;
            left++;
        }else if(s[left]=='+'){
            left++;
        }
        long long atoi=0;
        while (left<=right&&isdigit(s[left]))
        {
            atoi=(s[left]-'0')+atoi*10;
            bool isMax=MaxLarge(atoi*signal);
            if(isMax) return signal==1?INT_MAX:INT_MIN;
            left++;
        }
        return (int)atoi*signal;
    }
};
// @lc code=end
