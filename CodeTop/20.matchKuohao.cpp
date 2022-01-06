/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 * [easy]
 * https://leetcode-cn.com/problems/valid-parentheses/
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> match{
            {')','('},
            {']','['},
            {'}','{'}
        };
        if(s.size() % 2 != 0){
            return false;
        }
        stack<char> sk;
        for(int i = 0; i < s.size(); i++){
            if(match.find(s[i]) != match.end()){
                if(!sk.empty() && match[s[i]] == sk.top()){
                    sk.pop();
                }else{
                    return false;
                }
            }else{
                sk.push(s[i]);
            }
        }
        if(sk.empty()){
            return true;
        }
        return false;
    }
};
// @lc code=end

#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        int len = s.size();
        if(len % 2 != 0){
            return false;
        }
        unordered_map<char, char> map = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> sk;
        for(char k : s){
            // if(map.count(k)){
            if(map.find(k) != map.end()){
                if(sk.empty() || sk.top() != map[k]){
                    return false;
                }
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