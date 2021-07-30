/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 * [easy]
 * https://leetcode-cn.com/problems/valid-parentheses/
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int len=s.size();
        if(len%2!=0)
            return false;
        unordered_map<char,char> map={
            {')','('},
            {'}','{'},
            {']','['}
        };
        stack<char> sk;
        for(char k:s){
            if(map.count(k)){
                if(sk.empty()||sk.top()!=map[k])
                    return false;
                sk.pop();
            }else{
                sk.push(k);
            }
        }

        if(sk.empty())
            return true;
        return false;
    }
};
// @lc code=end

