/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 * [medium]
 * https://leetcode-cn.com/problems/string-to-integer-atoi/
 */

// @lc code=start
class Solution
{
    bool MaxInt(long long num){
        return num > INT_MAX || num < INT_MIN;
    }
public:
    int myAtoi(string s)
    {
        int i = 0;
        int len = s.size();
        int signal = 1;
        while (s[i] == ' ' && i < len)
        {
            i++;
        }
        if(s[i] == '-'){
            signal = -1;
            i++;
        }else if(s[i] == '+'){
            i++;
        }
        long long atoi = 0;
        while(i < len && isdigit(s[i])){
            atoi = atoi * 10 + s[i] - '0';
            if(MaxInt(atoi * signal)){
                return signal == 1 ? INT_MAX : INT_MIN;
            }
            i++;
        }
        return (int)atoi * signal;
    }
};
// @lc code=end


#define INT_MAX 2147483648
#define INT_MIN -2147483648
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
        int left = 0;
        int right = s.size();
        while(left < right && s[left] == ' '){
            left++;
        }
        int signal = 1;
        if(s[left] == '-'){
            signal = -1;
            left++;
        }else if(s[left] == '+'){
            left++;
        }
        long long atoi = 0;
        while (left < right && isdigit(s[left]))
        {
            atoi = (s[left] - '0') + atoi * 10;
            bool isMax = MaxLarge(atoi * signal);
            if(isMax){
                return signal == 1 ? INT_MAX : INT_MIN;
            }
            left++;
        }
        return (int)atoi * signal;
    }
};